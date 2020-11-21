/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** find_user_by_name
*/

#include "server.h"

struct user_s *find_user_by_name(struct suserhead *users, char *name)
{
    struct user_s *user = NULL;

    STAILQ_FOREACH(user, users, entries) {
        if (strcmp(user->name, name) == 0)
            return user;
    }
    return NULL;
}