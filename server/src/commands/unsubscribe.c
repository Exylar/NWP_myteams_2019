/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** unsubscribed
*/

#include "server.h"

static void log_infos(struct client_s *client, struct team_s *team)
{
    char unparsed_team_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_user_uuid[UUID_STR_LEN] = {'\0'};

    uuid_unparse(team->uuid, unparsed_team_uuid);
    uuid_unparse(client->uuid, unparsed_user_uuid);
    cprintf(client, UNSUB, unparsed_user_uuid, unparsed_team_uuid);
    server_event_user_leave_a_team(unparsed_team_uuid, unparsed_user_uuid);
}

void unsubscribe_cmd(struct client_s *client, struct suserhead *users UNU,
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
    uuid = find_sub_by_uuid(&team->uuids, client->uuid);
    if (!uuid) {
        cprintf(client, ALREADY_EXISTS);
        return;
    }
    STAILQ_REMOVE(&team->uuids, uuid, uuid_list_s, entries);
    log_infos(client, team);
}