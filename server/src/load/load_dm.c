/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_dm
*/

#include "load.h"

void load_dm(struct suserhead *head, char **args)
{
    struct dm_s *dm = calloc(1, sizeof(struct dm_s));
    struct user_s *user;
    uuid_t uuidbuf = {};

    if (uuid_parse(args[1], uuidbuf) == -1)
        return free(dm);
    user = find_user_by_uuid(head, uuidbuf);
    if (user == NULL)
        return free(dm);
    if (uuid_parse(args[2], dm->receiver_uuid) == -1)
        return free(dm);
    STAILQ_INIT(&dm->messages);
    STAILQ_INSERT_TAIL(&user->dms, dm, entries);
}
