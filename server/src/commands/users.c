/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "server.h"

static const char *USER_INFO_LIST = "\"%s\",\"%s\",\"%d\"";

void users_cmd(struct client_s *client, struct suserhead *users,
struct steamhead *teams UNU, char **params UNU)
{
    char uuid[UUID_STR_LEN] = {'\0'};
    char buffer[1024] = {'\0'};
    struct user_s *user = NULL;

    cprintf(client, "200 ");
    STAILQ_FOREACH(user, users, entries) {
        uuid_unparse(user->uuid, uuid);
        sprintf(buffer, USER_INFO_LIST, uuid, user->name,
user->clients.stqh_first != NULL);
        if (user->entries.stqe_next != NULL)
            strcat(buffer, ";");
        cprintf(client, buffer);
        memset(uuid, '\0', 37);
        memset(buffer, '\0', 1024);
    }
    cprintf(client, "\n");
}