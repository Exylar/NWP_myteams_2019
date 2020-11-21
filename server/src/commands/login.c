/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "server.h"

void handle_login(struct client_s *client, struct suserhead *users,
struct user_s *saved_user, char *username)
{
    char buffer[UUID_STR_LEN] = {'\0'};
    struct client_list_s *list = NULL;

    if (saved_user == NULL) {
        saved_user = new_user(client, username);
        STAILQ_INSERT_TAIL(users, saved_user, entries);
        uuid_unparse(saved_user->uuid, buffer);
        server_event_user_created(buffer, username);
    } else {
        list = new_client_list(client);
        STAILQ_INSERT_TAIL(&saved_user->clients,
list, entries);
        uuid_copy(client->uuid, saved_user->uuid);
    }
    uuid_unparse(saved_user->uuid, buffer);
    cprintf(client, LOGGED_IN, buffer, username);
    broadcast(client, users, BROADCAST_LOGIN, buffer, username);
    client->logged_in = true;
    server_event_user_logged_in(buffer);
}

void login_cmd(struct client_s *client, struct suserhead *users,
struct steamhead *teams UNU, char **params)
{
    struct user_s *saved_user = NULL;

    if (client->logged_in == true) {
        cprintf(client, ALREADY_CONNECTED);
        return;
    }
    saved_user = find_user_by_name(users, params[1]);
    handle_login(client, users, saved_user, params[1]);
}