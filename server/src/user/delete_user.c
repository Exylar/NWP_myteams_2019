/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_user
*/

#include "user.h"
#include <stdlib.h>

void delete_user(struct user_s *user)
{
    struct dm_s *dm = NULL;
    struct dm_s *old_ptr = NULL;

    if (user == NULL)
        return;
    free(user->name);
    STAILQ_FOREACH(dm, &user->dms, entries) {
        free(old_ptr);
        delete_dm(dm);
        old_ptr = dm;
    }
    free(old_ptr);
}
