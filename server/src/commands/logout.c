/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout
*/

#include "server.h"

void logout_cmd(struct client_s *client, struct suserhead *users UNU,
struct steamhead *teams UNU, char **params UNU)
{
    char buffer[UUID_STR_LEN] = {'\0'};
    struct user_s *user = NULL;

    uuid_unparse(client->uuid, buffer);
    server_event_user_logged_out(buffer);
    user = find_user_by_uuid(users, client->uuid);
    if (user) {
        cprintf(client, LOGGED_OUT, buffer, user->name);
        broadcast(client, users, BROADCAST_LOGOUT, buffer, user->name);
    } else {
        cprintf(client, LOGGED_OUT, "", "");
    }
    client->need_logout = true;
}