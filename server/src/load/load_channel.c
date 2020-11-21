/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_channel
*/

#include "load.h"
#include <string.h>

void load_channel(struct steamhead *head, char **args)
{
    struct channel_s *channel = calloc(1, sizeof(struct channel_s));
    struct team_s *team;
    uuid_t team_uuid = {};

    if (uuid_parse(args[1], team_uuid) == -1)
        return free(channel);
    team = find_team_by_uuid(head, team_uuid);
    if (team == NULL)
        return free(channel);
    if (uuid_parse(args[2], channel->uuid) == -1)
        return free(channel);
    channel->name = strdup(args[3]);
    channel->description = strdup(args[4]);
    STAILQ_INIT(&channel->threads);
    STAILQ_INSERT_TAIL(&team->channels, channel, entries);
}
