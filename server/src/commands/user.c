/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user
*/

#include "server.h"

void user_cmd(struct client_s *client, struct suserhead *users,
struct steamhead *teams UNU, char **params)
{
    struct user_s *user = NULL;
    uuid_t to_find = {0};
    char buffer[UUID_STR_LEN] = {'\0'};

    if (uuid_parse(params[1], to_find) == -1) {
        cprintf(client, INVALID_UUID, "user", params[1]);
        return;
    }
    user = find_user_by_uuid(users, to_find);
    if (!user) {
        cprintf(client, INVALID_UUID, "user", params[1]);
    } else {
        uuid_unparse(user->uuid, buffer);
        cprintf(client, USER_INFO, buffer, user->name,
user->clients.stqh_first != NULL);
    }
}
