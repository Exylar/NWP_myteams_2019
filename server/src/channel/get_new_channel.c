/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_new_channel
*/

#include "server.h"

struct channel_s *get_new_channel(char *name, char *description)
{
    struct channel_s *new_channel = malloc(sizeof(struct channel_s));

    new_channel->name = strdup(name);
    new_channel->description = strdup(description);
    uuid_generate(new_channel->uuid);
    STAILQ_INIT(&new_channel->threads);
    return new_channel;
}