/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** find_thread_by_uuid
*/

#include "server.h"

struct thread_s *find_thread_by_uuid(struct sthreadhead *threads,
uuid_t to_find)
{
    struct thread_s *thread = NULL;

    STAILQ_FOREACH(thread, threads, entries) {
        if (uuid_compare(thread->uuid, to_find) == 0)
            return thread;
    }
    return NULL;
}