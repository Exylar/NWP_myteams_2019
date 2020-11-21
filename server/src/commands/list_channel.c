/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_channel
*/

#include "server.h"

static const char *CHANNEL_INFO_LIST = "\"%s\",\"%s\",\"%s\"";

static void send_infos(struct client_s *client, struct team_s *team)
{
    char unparsed_channel_uuid[UUID_STR_LEN] = {'\0'};
    struct channel_s *channel = NULL;

    cprintf(client, "200 ");
    STAILQ_FOREACH(channel, &team->channels, entries) {
        uuid_unparse(channel->uuid, unparsed_channel_uuid);
        cprintf(client, CHANNEL_INFO_LIST, unparsed_channel_uuid, channel->name,
channel->description);
        if (channel->entries.stqe_next != NULL)
            cprintf(client, ";");
        memset(unparsed_channel_uuid, '\0', UUID_STR_LEN);
    }
    cprintf(client, "\n");
}

static bool get_mandatory_infos(struct client_s *client, uuid_t team_uuid,
char **params)
{
    if (uuid_parse(params[2], team_uuid) == -1) {
        cprintf(client, INVALID_UUID, "team", params[2]);
        return false;
    }
    return true;
}

void list_channel(struct client_s *client, struct suserhead *users UNU,
struct steamhead *teams, char **params)
{
    uuid_t team_uuid = {'\0'};
    struct team_s *team = NULL;

    if (get_mandatory_infos(client, team_uuid, params) == false)
        return;
    team = get_team(teams, team_uuid, client);
    if (!team)
        return;
    send_infos(client, team);
}