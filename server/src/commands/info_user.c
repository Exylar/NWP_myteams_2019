/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info_user
*/

#include "server.h"

void info_user(struct client_s *client, struct suserhead *users,
struct steamhead *teams UNU, char **params UNU)
{
    struct user_s *user = find_user_by_uuid(users, client->uuid);
    char user_uuid[UUID_STR_LEN] = {'\0'};

    uuid_unparse(user->uuid, user_uuid);
    cprintf(client, USER_INFO, user_uuid, user->name, 1);
}