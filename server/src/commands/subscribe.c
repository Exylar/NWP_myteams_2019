/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribe
*/

#include "server.h"

static void log_infos(struct client_s *client, struct team_s *team)
{
    char unparsed_team_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_user_uuid[UUID_STR_LEN] = {'\0'};

    uuid_unparse(team->uuid, unparsed_team_uuid);
    uuid_unparse(client->uuid, unparsed_user_uuid);
    cprintf(client, SUB, unparsed_user_uuid, unparsed_team_uuid);
    server_event_user_join_a_team(unparsed_team_uuid, unparsed_user_uuid);
}

void subscribe_cmd(struct client_s *client, struct suserhead *users UNU,
struct steamhead *teams, char **params)
{
    uuid_t team_uuid = {'\0'};

    struct team_s *team = NULL;
    struct uuid_list_s *uuid = NULL;

    if (uuid_parse(params[1], team_uuid) == -1) {
        cprintf(client, INVALID_UUID, "team", params[1]);
        return;
    }
    team = get_team(teams, team_uuid, client);
    if (!team)
        return;
    if (find_sub_by_uuid(&team->uuids, client->uuid) != NULL) {
        cprintf(client, ALREADY_EXISTS);
        return;
    }
    uuid = malloc(sizeof(struct uuid_list_s));
    uuid_copy(uuid->uuid, client->uuid);
    STAILQ_INSERT_TAIL(&team->uuids, uuid, entries);
    log_infos(client, team);
}