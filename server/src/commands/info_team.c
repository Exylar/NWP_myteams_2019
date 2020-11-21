/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info_team
*/

#include "server.h"

void info_team(struct client_s *client, struct suserhead *users UNU,
struct steamhead *teams, char **params)
{
    uuid_t team_uuid = {'\0'};
    char unparsed_team_uuid[UUID_STR_LEN] = {'\0'};
    struct team_s *team = NULL;

    if (uuid_parse(params[2], team_uuid) == -1) {
        cprintf(client, INVALID_UUID, "team", params[2]);
        return;
    }
    team = get_team(teams, team_uuid, client);
    if (!team)
        return;
    uuid_unparse(team_uuid, unparsed_team_uuid);
    cprintf(client, TEAM_INFO, unparsed_team_uuid, team->name,
team->description);
}