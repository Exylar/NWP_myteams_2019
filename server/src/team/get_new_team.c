/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_new_team
*/

#include "server.h"

struct team_s *get_new_team(char *name, char *description)
{
    struct team_s *new_team = calloc(1, sizeof(struct team_s));

    uuid_generate(new_team->uuid);
    new_team->name = strdup(name);
    new_team->description = strdup(description);
    STAILQ_INIT(&new_team->uuids);
    STAILQ_INIT(&new_team->channels);
    return new_team;
}