/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** find_team_by_name
*/

#include "server.h"

struct team_s *find_team_by_name(struct steamhead *teams, char *name)
{
    struct team_s *team = NULL;

    STAILQ_FOREACH(team, teams, entries) {
        if (strcmp(team->name, name) == 0)
            return team;
    }
    return NULL;
}