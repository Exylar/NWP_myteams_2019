/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** find_user_by_uuid
*/

#include "server.h"

struct user_s *find_user_by_uuid(struct suserhead *users, uuid_t uuid)
{
    struct user_s *user = NULL;

    STAILQ_FOREACH(user, users, entries) {
        if (uuid_compare(user->uuid, uuid) == 0)
            return user;
    }
    return NULL;
}
