/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team
*/

#include "save.h"

static void save_channel(struct channel_s *channel, FILE *file,
char *unparsed_team_uuid)
{
    char unparsed_channel_uuid[UUID_STR_LEN] = {'\0'};

    uuid_unparse(channel->uuid, unparsed_channel_uuid);
    fprintf(file, "CHANNEL,\"%s\",\"%s\",\"%s\",\"%s\"\n", unparsed_team_uuid,
unparsed_channel_uuid, channel->name, channel->description);
    save_threads(&channel->threads, file, unparsed_team_uuid,
unparsed_channel_uuid);
}

void save_channels(struct schannelhead *channels, FILE *file,
char *unparsed_team_uuid)
{
    struct channel_s *channel = NULL;

    STAILQ_FOREACH(channel, channels, entries) {
        save_channel(channel, file, unparsed_team_uuid);
    }
}