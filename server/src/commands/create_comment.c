/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_comment
*/

#include <stdarg.h>
#include "server.h"

static void tell_to_others(struct client_s *client, struct team_s *team,
struct suserhead *users, char **values)
{
    char *comment = NULL;
    char *user_uuid = NULL;
    char team_uuid[UUID_STR_LEN] = {'\0'};
    char *thread_uuid = NULL;

    comment = values[0];
    thread_uuid = values[1];
    user_uuid = values[2];
    uuid_unparse(team->uuid, team_uuid);
    broadcast_to_subs(client, team, users, BROADCAST_COMMENT, team_uuid,
thread_uuid, user_uuid, comment);
    free(values[1]);
    free(values[2]);
}

static void log_infos(struct client_s *client, struct thread_s *thread,
struct message_s *comment, char **values)
{
    char user_uuid[UUID_STR_LEN] = {'\0'};
    char thread_uuid[UUID_STR_LEN] = {'\0'};

    uuid_unparse(client->uuid, user_uuid);
    uuid_unparse(thread->uuid, thread_uuid);
    cprintf(client, COMMENT_CREATED, thread_uuid, user_uuid,
comment->timestamp, comment->message);
    values[0] = comment->message;
    values[1] = strdup(thread_uuid);
    values[2] = strdup(user_uuid);
    server_event_thread_new_message(thread_uuid, user_uuid, comment->message);
}

static bool get_mandatory_infos(struct client_s *client, char **params,
uuid_t *uuids)
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

static struct thread_s *fetch_thread(struct client_s *client,
struct team_s *team, uuid_t *uuids)
{
    struct channel_s *channel = NULL;
    struct thread_s *thread = NULL;

    channel = get_channel(&team->channels, uuids[1], client);
    if (!channel)
        return NULL;
    thread = get_thread(&channel->threads, uuids[2], client);
    if (!thread)
        return NULL;
    return thread;
}

void create_comment(struct client_s *client, struct suserhead *users,
struct steamhead *teams, char **params)
{
    uuid_t uuids[3] = {'\0'};
    struct team_s *team = NULL;
    struct thread_s *thread = NULL;
    struct message_s *comment = NULL;
    struct user_s *user = find_user_by_uuid(users, client->uuid);
    char **values = malloc(sizeof(char *) * 3);

    if (get_mandatory_infos(client, params, uuids) == false)
        return;
    team = get_team(teams, uuids[0], client);
    if (!team)
        return;
    if (find_sub_by_uuid(&team->uuids, client->uuid) == NULL)
        return cprintf(client, NOT_SUB);
    thread = fetch_thread(client, team, uuids);
    if (!thread)
        return;
    comment = get_new_comment(params[5], user->uuid);
    STAILQ_INSERT_TAIL(&thread->comments, comment, entries);
    log_infos(client, thread, comment, values);
    tell_to_others(client, team, users, values);
}