/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_team
*/

#include "server.h"

void create_team(struct client_s *client, struct suserhead *users,
struct steamhead *teams, char **params)
{
    struct team_s *new_team = NULL;
    char team_uuid[UUID_STR_LEN] = {'\0'};
    char client_uuid[UUID_STR_LEN] = {'\0'};

    if (find_team_by_name(teams, params[2]) != NULL) {
        cprintf(client, ALREADY_EXISTS);
        return;
    }
    new_team = get_new_team(params[2], params[3]);
    STAILQ_INSERT_TAIL(teams, new_team, entries);
    uuid_unparse(new_team->uuid, team_uuid);
    uuid_unparse(client->uuid, client_uuid);
    server_event_team_created(team_uuid, new_team->name, client_uuid);
    cprintf(client, TEAM_CREATED, team_uuid, new_team->name,
new_team->description);
    broadcast(client, users, BROADCAST_TEAM, team_uuid, new_team->name,
new_team->description);
}