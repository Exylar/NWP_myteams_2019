/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_message
*/

#include "load.h"
#include <string.h>

static struct thread_s *find_thread(struct steamhead *head, char *team_uuid,
    char *channel_uuid, char *thread_uuid)
{
    struct team_s *team;
    struct channel_s *channel;
    uuid_t uuidbuf = {};

    if (uuid_parse(team_uuid, uuidbuf) == -1)
        return NULL;
    team = find_team_by_uuid(head, uuidbuf);
    if (team == NULL)
        return NULL;
    if (uuid_parse(channel_uuid, uuidbuf) == -1)
        return NULL;
    channel = find_channel_by_uuid(&team->channels, uuidbuf);
    if (channel == NULL)
        return NULL;
    if (uuid_parse(thread_uuid, uuidbuf) == -1)
        return NULL;
    return find_thread_by_uuid(&channel->threads, uuidbuf);
}

void load_comment(struct steamhead *head, char **args)
{
    struct message_s *comment = calloc(1, sizeof(struct message_s));
    struct thread_s *thread = find_thread(head, args[1], args[2], args[3]);
    char *ptr;

    if (thread == NULL)
        return free(comment);
    if (uuid_parse(args[4], comment->sender_uuid) == -1)
        return free(comment);
    comment->message = strdup(args[5]);
    comment->timestamp = strtol(args[6], &ptr, 10);
    if (*ptr != '\0')
        return free(comment);
    STAILQ_INSERT_TAIL(&thread->comments, comment, entries);
}
