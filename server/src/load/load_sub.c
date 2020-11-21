/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_sub
*/

#include "load.h"

void load_sub(struct steamhead *head, char **args)
{
    struct uuid_list_s *sub = calloc(1, sizeof(struct uuid_list_s));
    struct team_s *team;
    uuid_t team_uuid = {};

    if (uuid_parse(args[1], team_uuid) == -1)
        return free(sub);
    team = find_team_by_uuid(head, team_uuid);
    if (team == NULL)
        return free(sub);
    if (uuid_parse(args[2], sub->uuid) == -1)
        return free(sub);
    STAILQ_INSERT_TAIL(&team->uuids, sub, entries);
}
