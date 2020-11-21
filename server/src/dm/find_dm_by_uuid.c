/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** find_dm_by_username
*/

#include "server.h"

struct dm_s *find_dm_by_uuid(struct sdmhead *dms, uuid_t to_find)
{
    struct dm_s *dm = NULL;

    STAILQ_FOREACH(dm, dms, entries) {
        if (uuid_compare(to_find, dm->receiver_uuid) == 0)
            return dm;
    }
    return NULL;
}