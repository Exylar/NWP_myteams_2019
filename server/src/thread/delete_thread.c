/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_thread
*/

#include <stdlib.h>
#include "thread.h"

void delete_thread(struct thread_s *thread)
{
    struct message_s *message = NULL;
    struct message_s *old_ptr = NULL;

    if (thread == NULL)
        return;
    free(thread->title);
    free(thread->body);
    STAILQ_FOREACH(message, &thread->comments, entries) {
        free(old_ptr);
        delete_comment(message);
        old_ptr = message;
    }
    free(old_ptr);
}