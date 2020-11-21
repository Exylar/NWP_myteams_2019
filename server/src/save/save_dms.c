/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save_dms
*/

#include "save.h"

static void save_dm(struct dm_s *dm, FILE *file, char *unparsed_user_uuid)
{
    char unparsed_receiver_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_uuids[4096] = {'\0'};

    uuid_unparse(dm->receiver_uuid, unparsed_receiver_uuid);
    fprintf(file, "DM,\"%s\",\"%s\"\n", unparsed_user_uuid,
unparsed_receiver_uuid);
    sprintf(unparsed_uuids, "\"%s\",\"%s\"", unparsed_user_uuid,
unparsed_receiver_uuid);
    save_messages(&dm->messages, file, unparsed_uuids, "MESSAGE");
}

void save_dms(struct sdmhead *dms, FILE *file, char *unparsed_user_uuid)
{
    struct dm_s *dm = NULL;

    STAILQ_FOREACH(dm, dms, entries) {
        save_dm(dm, file, unparsed_user_uuid);
    }
}