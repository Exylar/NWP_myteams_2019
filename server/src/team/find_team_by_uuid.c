/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** find_team_by_uuid
*/

#include "server.h"

struct team_s *find_team_by_uuid(struct steamhead *teams, uuid_t to_find)
{
    struct team_s *team = NULL;

    STAILQ_FOREACH(team, teams, entries) {
        if (uuid_compare(team->uuid, to_find) == 0)
            return team;
    }
    return NULL;
}