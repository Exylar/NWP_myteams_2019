/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_thread
*/

#include "server.h"

static const char *THREAD_INFO_LIST = "\"%s\",\"%s\",\"%lu\",\"%s\",\"%s\"";

static void send_infos(struct client_s *client, struct channel_s *channel)
{
    char unparsed_thread_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_user_uuid[UUID_STR_LEN] = {'\0'};
    struct thread_s *thread = NULL;

    cprintf(client, "200 ");
    STAILQ_FOREACH(thread, &channel->threads, entries) {
        uuid_unparse(thread->uuid, unparsed_thread_uuid);
        uuid_unparse(thread->user_uuid, unparsed_user_uuid);
        cprintf(client, THREAD_INFO_LIST, unparsed_thread_uuid,
unparsed_user_uuid, thread->timestamp, thread->title, thread->body);
        if (thread->entries.stqe_next != NULL)
            cprintf(client, ";");
        memset(unparsed_thread_uuid, '\0', UUID_STR_LEN);
        memset(unparsed_user_uuid, '\0', UUID_STR_LEN);
    }
    cprintf(client, "\n");
}

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

void list_thread(struct client_s *client, struct suserhead *users UNU,
struct steamhead *teams, char **params)
{
    uuid_t team_uuid = {'\0'};
    uuid_t channel_uuid = {'\0'};
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
    send_infos(client, channel);
}