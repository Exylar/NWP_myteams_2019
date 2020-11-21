/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_users
*/

#include "load.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

void load_user(struct suserhead *head, char **args)
{
    struct user_s *user = calloc(1, sizeof(struct user_s));

    if (uuid_parse(args[1], user->uuid) == -1)
        return free(user);
    user->name = strdup(args[2]);
    STAILQ_INSERT_TAIL(head, user, entries);
    STAILQ_INIT(&user->clients);
    STAILQ_INIT(&user->dms);
}
