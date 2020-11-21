/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** find_sub_by_uuid
*/

#include "server.h"

struct uuid_list_s *find_sub_by_uuid(struct suuidhead *uuids, uuid_t to_find)
{
    struct uuid_list_s *uuid = NULL;

    STAILQ_FOREACH(uuid, uuids, entries) {
        if (uuid_compare(to_find, uuid->uuid) == 0)
            return uuid;
    }
    return NULL;
}