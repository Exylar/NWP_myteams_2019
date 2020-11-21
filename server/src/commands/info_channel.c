/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info_channel
*/

#include "server.h"

static bool get_mandatory_infos(struct client_s *client, uuid_t team_uuid,
uuid_t channel_uuid, char **params)
{
    if (uuid_parse(params[2], team_uuid) == -1) {
        cprintf(client, INVALID_UUID, "team", params[2]);
        return false;
    }
    if (uuid_parse(params[3], channel_uuid) == -1) {
        cprintf(client, INVALID_UUID, "channel", params[3]);
        return false;
    }
    return true;
}

void info_channel(struct client_s *client, struct suserhead *users UNU,
struct steamhead *teams, char **params)
{
    uuid_t team_uuid = {'\0'};
    uuid_t channel_uuid = {'\0'};
    char unparsed_channel_uuid[UUID_STR_LEN] = {'\0'};
    struct team_s *team = NULL;
    struct channel_s *channel = NULL;

    if (get_mandatory_infos(client, team_uuid, channel_uuid, params) == false)
        return;
    team = get_team(teams, team_uuid, client);
    if (!team)
        return;
    channel = get_channel(&team->channels, channel_uuid, client);
    if (!channel)
        return;
    uuid_unparse(team_uuid, unparsed_channel_uuid);
    cprintf(client, CHANNEL_INFO, unparsed_channel_uuid, channel->name,
channel->description);
}