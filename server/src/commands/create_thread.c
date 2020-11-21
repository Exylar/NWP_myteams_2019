/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_thread
*/

#include "server.h"

static void tell_to_others(struct client_s *client, struct suserhead *users,
struct team_s *team, struct thread_s *thread)
{
    char unparsed_thread_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_user_uuid[UUID_STR_LEN] = {'\0'};

    uuid_unparse(thread->uuid, unparsed_thread_uuid);
    uuid_unparse(client->uuid, unparsed_user_uuid);
    broadcast_to_subs(client, team, users, BROADCAST_THREAD,
unparsed_thread_uuid, unparsed_user_uuid, thread->timestamp,
thread->title, thread->body);
}

static void log_infos(struct channel_s *channel, struct thread_s *thread,
struct client_s *client)
{
    char unparsed_channel_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_thread_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_user_uuid[UUID_STR_LEN] = {'\0'};

    uuid_unparse(channel->uuid, unparsed_channel_uuid);
    uuid_unparse(thread->uuid, unparsed_thread_uuid);
    uuid_unparse(client->uuid, unparsed_user_uuid);
    server_event_thread_created(unparsed_channel_uuid, unparsed_thread_uuid,
unparsed_user_uuid, thread->body);
    cprintf(client, THREAD_CREATED, unparsed_thread_uuid, unparsed_user_uuid,
thread->timestamp, thread->title, thread->body);
}

static bool get_mandatory_infos(struct client_s *client, char **params,
uuid_t team_uuid, uuid_t channel_uuid)
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

void create_thread(struct client_s *client, struct suserhead *users,
struct steamhead *teams, char **params)
{
    uuid_t team_uuid = {'\0'};
    uuid_t channel_uuid = {'\0'};
    struct team_s *team = NULL;
    struct channel_s *channel = NULL;
    struct thread_s *thread = NULL;

    if (get_mandatory_infos(client, params,
team_uuid, channel_uuid) == false)
        return;
    team = get_team(teams, team_uuid, client);
    if (!team)
        return;
    if (find_sub_by_uuid(&team->uuids, client->uuid) == NULL)
        return cprintf(client, NOT_SUB);
    channel = get_channel(&team->channels, channel_uuid, client);
    if (!channel)
        return;
    thread = get_new_thread(params[4], params[5], client->uuid);
    STAILQ_INSERT_TAIL(&channel->threads, thread, entries);
    log_infos(channel, thread, client);
    tell_to_others(client, users, team, thread);
}