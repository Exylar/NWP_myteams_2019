/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** new_user
*/

#include "user.h"
#include <stdlib.h>
#include <string.h>

struct user_s *new_user(struct client_s *client, char *name)
{
    struct user_s *new_user = malloc(sizeof(struct user_s));
    struct client_list_s *list = NULL;

    new_user->name = strdup(name);
    uuid_generate(new_user->uuid);
    uuid_copy(client->uuid, new_user->uuid);
    STAILQ_INIT(&new_user->dms);
    STAILQ_INIT(&new_user->clients);
    list = new_client_list(client);
    STAILQ_INSERT_TAIL(&new_user->clients, list, entries);
    return new_user;
}
