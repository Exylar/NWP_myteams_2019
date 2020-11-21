/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_channel
*/

#include "server.h"

static void log_values(struct client_s *client, struct team_s *team,
struct channel_s *channel, struct suserhead *users)
{
    char team_uuid[UUID_STR_LEN] = {'\0'};
    char channel_uuid[UUID_STR_LEN] = {'\0'};

    uuid_unparse(team->uuid, team_uuid);
    uuid_unparse(channel->uuid, channel_uuid);
    server_event_channel_created(team_uuid, channel_uuid, channel->name);
    cprintf(client, CHANNEL_CREATED, channel_uuid, channel->name,
channel->description);
    broadcast_to_subs(client, team, users, BROADCAST_CHANNEL, channel_uuid,
channel->name, channel->description);
}

static bool get_mandatory_infos(char **params, uuid_t team_uuid,
struct client_s *client)
{
    if (uuid_parse(params[2], team_uuid) == -1) {
        cprintf(client, INVALID_UUID, "team", params[2]);
        return false;
    }
    return true;
}

void create_channel(struct client_s *client, struct suserhead *users,
struct steamhead *teams, char **params)
{
    uuid_t team_uuid = {'\0'};
    struct team_s *team = NULL;
    struct channel_s *channel = NULL;

    if (get_mandatory_infos(params, team_uuid, client) == false)
        return;
    team = get_team(teams, team_uuid, client);
    if (!team)
        return;
    if (find_sub_by_uuid(&team->uuids, client->uuid) == NULL)
        return cprintf(client, NOT_SUB);
    if (find_channel_by_name(&team->channels, params[3]) != NULL)
        return cprintf(client, ALREADY_EXISTS);
    channel = get_new_channel(params[3], params[4]);
    STAILQ_INSERT_TAIL(&team->channels, channel, entries);
    log_values(client, team, channel, users);
}