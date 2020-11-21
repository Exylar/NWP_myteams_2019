/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_thread
*/

#include "load.h"
#include <string.h>

static struct channel_s *find_channel(
    struct steamhead *head, char *team_uuid, char *channel_uuid)
{
    struct team_s *team;
    uuid_t uuidbuf = {};

    if (uuid_parse(team_uuid, uuidbuf) == -1)
        return NULL;
    team = find_team_by_uuid(head, uuidbuf);
    if (team == NULL)
        return NULL;
    if (uuid_parse(channel_uuid, uuidbuf) == -1)
        return NULL;
    return find_channel_by_uuid(&team->channels, uuidbuf);
}

void load_thread(struct steamhead *head, char **args)
{
    struct thread_s *thread = calloc(1, sizeof(struct thread_s));
    struct channel_s *channel = find_channel(head, args[1], args[2]);
    char *ptr;

    if (channel == NULL)
        return free(thread);
    if (uuid_parse(args[3], thread->uuid) == -1
        || uuid_parse(args[4], thread->user_uuid) == -1)
        return free(thread);
    thread->title = strdup(args[5]);
    thread->body = strdup(args[6]);
    thread->timestamp = strtol(args[7], &ptr, 10);
    if (*ptr != '\0')
        return free(thread);
    STAILQ_INIT(&thread->comments);
    STAILQ_INSERT_TAIL(&channel->threads, thread, entries);
}
