/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_new_thead
*/

#include "server.h"

struct thread_s *get_new_thread(char *name, char *body, uuid_t user_uuid)
{
    struct thread_s *new_thread = calloc(1, sizeof(struct thread_s));

    new_thread->title = strdup(name);
    new_thread->body = strdup(body);
    new_thread->timestamp = time(NULL);
    STAILQ_INIT(&new_thread->comments);
    uuid_copy(new_thread->user_uuid, user_uuid);
    uuid_generate(new_thread->uuid);
    return new_thread;
}