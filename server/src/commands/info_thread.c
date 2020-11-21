/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info_thread
*/

#include "server.h"

static bool get_mandatory_infos(struct client_s *client, uuid_t *uuids,
char **params)
{
    if (uuid_parse(params[2], uuids[0]) == -1) {
        cprintf(client, INVALID_UUID, "team", params[2]);
        return false;
    }
    if (uuid_parse(params[3], uuids[1]) == -1) {
        cprintf(client, INVALID_UUID, "channel", params[3]);
        return false;
    }
    if (uuid_parse(params[4], uuids[2]) == -1) {
        cprintf(client, INVALID_UUID, "thread", params[4]);
        return false;
    }
    return true;
}

void info_thread(struct client_s *client, struct suserhead *users UNU,
struct steamhead *teams, char **params)
{
    uuid_t uuids[3] = {'\0'};
    char unparsed_uuids[2][UUID_STR_LEN] = {'\0'};
    struct team_s *team = NULL;
    struct channel_s *channel = NULL;
    struct thread_s *thread = NULL;

    if (get_mandatory_infos(client, uuids, params) == false)
        return;
    team = get_team(teams, uuids[0], client);
    if (!team)
        return;
    channel = get_channel(&team->channels, uuids[1], client);
    if (!channel)
        return;
    thread = get_thread(&channel->threads, uuids[2], client);
    if (!thread)
        return;
    uuid_unparse(uuids[2], unparsed_uuids[0]);
    uuid_unparse(thread->user_uuid, unparsed_uuids[1]);
    cprintf(client, THREAD_INFO, unparsed_uuids[0],
unparsed_uuids[1], thread->timestamp, thread->title, thread->body);
}