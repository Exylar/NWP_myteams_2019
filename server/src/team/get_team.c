/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_team
*/

#include "server.h"

struct team_s *get_team(struct steamhead *teams, uuid_t team_uuid,
struct client_s *client)
{
    struct team_s *team = find_team_by_uuid(teams, team_uuid);
    char unparsed_team_uuid[UUID_STR_LEN] = {'\0'};

    if (!team) {
        uuid_unparse(team_uuid, unparsed_team_uuid);
        cprintf(client, INVALID_UUID, "team", unparsed_team_uuid);
        return NULL;
    }
    return team;
}