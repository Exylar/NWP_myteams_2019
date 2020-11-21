/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** find_channel_by_uuid
*/

#include "server.h"

struct channel_s *find_channel_by_uuid(struct schannelhead *channels,
uuid_t uuid)
{
    for (struct channel_s *channel = channels->stqh_first; channel != NULL;
channel = channel->entries.stqe_next) {
        if (uuid_compare(channel->uuid, uuid) == 0)
            return channel;
    }
    return NULL;
}