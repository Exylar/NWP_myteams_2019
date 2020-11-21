/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** find_thread_by_name
*/

#include "server.h"

struct thread_s *find_thread_by_name(struct sthreadhead *threads, char *name)
{
    struct thread_s *thread = NULL;

    STAILQ_FOREACH(thread, threads, entries) {
        if (strcmp(thread->title, name) == 0)
            return thread;
    }
    return NULL;
}