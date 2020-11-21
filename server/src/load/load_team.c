/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_team
*/

#include "load.h"
#include <string.h>

void load_team(struct steamhead *head, char **args)
{
    struct team_s *team = calloc(1, sizeof(struct team_s));

    if (uuid_parse(args[1], team->uuid) == -1)
        return free(team);
    team->name = strdup(args[2]);
    team->description = strdup(args[3]);
    STAILQ_INIT(&team->uuids);
    STAILQ_INIT(&team->channels);
    STAILQ_INSERT_TAIL(head, team, entries);
}
