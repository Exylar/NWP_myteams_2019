/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_channel
*/

#include "server.h"

struct channel_s *get_channel(struct schannelhead *channels,
uuid_t channel_uuid, struct client_s *client)
{
    struct channel_s *channel = find_channel_by_uuid(channels, channel_uuid);
    char unparsed_channel_uuid[UUID_STR_LEN] = {'\0'};

    if (!channel) {
        uuid_unparse(channel_uuid, unparsed_channel_uuid);
        cprintf(client, INVALID_UUID, "channel", unparsed_channel_uuid);
        return NULL;
    }
    return channel;
}