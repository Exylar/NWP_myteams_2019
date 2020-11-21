/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_channel
*/

#include <stdlib.h>
#include "channel.h"

void delete_channel(struct channel_s *channel)
{
    struct thread_s *thread = NULL;
    struct thread_s *old_ptr = NULL;

    if (channel == NULL)
        return;
    free(channel->name);
    free(channel->description);
    STAILQ_FOREACH(thread, &channel->threads, entries) {
        free(old_ptr);
        delete_thread(thread);
        old_ptr = thread;
    }
    free(old_ptr);
}