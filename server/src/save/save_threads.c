/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team
*/

#include "save.h"

static void save_thread(struct thread_s *thread, FILE *file,
char *unparsed_team_uuid, char *unparsed_channel_uuid)
{
    char unparsed_thread_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_user_uuid[UUID_STR_LEN] = {'\0'};
    char unparsed_uuids[4096] = {'\0'};

    uuid_unparse(thread->uuid, unparsed_thread_uuid);
    uuid_unparse(thread->user_uuid, unparsed_user_uuid);
    fprintf(file, "THREAD,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%lu\"\n",
unparsed_team_uuid, unparsed_channel_uuid, unparsed_thread_uuid,
unparsed_user_uuid, thread->title, thread->body,
thread->timestamp);
    sprintf(unparsed_uuids, "\"%s\",\"%s\",\"%s\"", unparsed_team_uuid,
unparsed_channel_uuid, unparsed_thread_uuid);
    save_messages(&thread->comments, file, unparsed_uuids, "COMMENT");
}

void save_threads(struct sthreadhead *threads, FILE *file,
char *unparsed_team_uuid, char *unparsed_channel_uuid)
{
    struct thread_s *thread = NULL;

    STAILQ_FOREACH(thread, threads, entries) {
        save_thread(thread, file, unparsed_team_uuid, unparsed_channel_uuid);
    }
}
