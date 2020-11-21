/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribed
*/

#include "server.h"

static const char *SUB_INFO = "\"%s\",\"%s\"";

static void get_subscribed_team(struct client_s *client,
struct steamhead *teams)
{
    struct uuid_list_s *uuid = NULL;
    char unparsed_team_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_user_uuid[UUID_STR_LEN] = {'\0'};
    bool has_semicolon = true;

    uuid_unparse(client->uuid, unparsed_user_uuid);
    for (struct team_s *team = teams->stqh_first; team != NULL;
team = team->entries.stqe_next) {
        uuid = find_sub_by_uuid(&team->uuids, client->uuid);
        if (!uuid)
            continue;
        if (has_semicolon == false) {
            cprintf(client, ";");
            has_semicolon = true;
        } else
            has_semicolon = false;
        uuid_unparse(team->uuid, unparsed_team_uuid);
        cprintf(client, SUB_INFO, unparsed_user_uuid, unparsed_team_uuid);
        memset(unparsed_team_uuid, '\0', UUID_STR_LEN);
    }
}

static void get_user_subscribed_to_team(struct client_s *client,
struct team_s *team)
{
    char unparsed_team_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_user_uuid[UUID_STR_LEN] = {'\0'};
    struct uuid_list_s *uuid = NULL;

    uuid_unparse(team->uuid, unparsed_team_uuid);
    cprintf(client, "200 ");
    STAILQ_FOREACH(uuid, &team->uuids, entries) {
        uuid_unparse(uuid->uuid, unparsed_user_uuid);
        cprintf(client, SUB_INFO, unparsed_user_uuid, unparsed_team_uuid);
        if (uuid->entries.stqe_next != NULL)
            cprintf(client, ";");
        memset(unparsed_user_uuid, '\0', UUID_STR_LEN);
    }
    cprintf(client, "\n");
}

void subscribed_cmd(struct client_s *client, struct suserhead *users UNU,
struct steamhead *teams, char **params)
{
    uuid_t team_uuid = {'\0'};
    struct team_s *team = NULL;

    if (params[1] == NULL) {
        cprintf(client, "200 ");
        get_subscribed_team(client, teams);
        return cprintf(client, "\n");
    }
    if (uuid_parse(params[1], team_uuid) == -1) {
        cprintf(client, INVALID_UUID, "team", params[1]);
        return;
    }
    team = find_team_by_uuid(teams, team_uuid);
    if (!team) {
        cprintf(client, INVALID_UUID, "team", params[1]);
        return;
    }
    get_user_subscribed_to_team(client, team);
}