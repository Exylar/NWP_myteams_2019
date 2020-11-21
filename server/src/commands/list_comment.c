/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_comment
*/

#include "server.h"

static const char *COMMENT_INFO_LIST = "\"%s\",\"%s\",\"%lu\",\"%s\"";

static void send_infos(struct client_s *client, struct thread_s *thread)
{
    char unparsed_thread_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_user_uuid[UUID_STR_LEN] = {'\0'};
    struct message_s *comment = NULL;

    uuid_unparse(thread->uuid, unparsed_thread_uuid);
    uuid_unparse(thread->user_uuid, unparsed_user_uuid);
    cprintf(client, "200 ");
    STAILQ_FOREACH(comment, &thread->comments, entries) {
        cprintf(client, COMMENT_INFO_LIST, unparsed_thread_uuid,
unparsed_user_uuid, comment->timestamp, comment->message);
        if (comment->entries.stqe_next != NULL)
            cprintf(client, ";");
    }
    cprintf(client, "\n");
}

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

void list_comment(struct client_s *client, struct suserhead *users UNU,
struct steamhead *teams, char **params)
{
    uuid_t uuids[3] = {'\0'};
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
    send_infos(client, thread);
}