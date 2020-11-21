/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** find_channel_by_name
*/

#include "server.h"

struct channel_s *find_channel_by_name(struct schannelhead *channels,
char *name)
{
    for (struct channel_s *channel = channels->stqh_first; channel != NULL;
channel = channel->entries.stqe_next) {
        if (strcmp(channel->name, name) == 0)
            return channel;
    }
    return NULL;
}