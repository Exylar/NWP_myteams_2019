/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_dm
*/

#include <stdlib.h>
#include "user.h"

void delete_dm(struct dm_s *dm)
{
    struct message_s *message = NULL;
    struct message_s *old_ptr = NULL;

    if (dm == NULL)
        return;
    STAILQ_FOREACH(message, &dm->messages, entries) {
        free(old_ptr);
        delete_comment(message);
        old_ptr = message;
    }
    free(old_ptr);
}