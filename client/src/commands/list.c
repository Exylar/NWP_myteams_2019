/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list
*/

#include "commands.h"
#include "consts.h"

void send_message_list(client_t *client)
{
    if (!client->context->uuid_team) {
        sprintf(client->sockets->buffer, "%s\n", LIST_TEAM);
        return;
    }
    if (!client->context->uuid_channel) {
        sprintf(client->sockets->buffer, "%s,\"%s\"\n", LIST_CHANNEL,
        client->context->uuid_team);
        return;
    }
    if (!client->context->uuid_thread) {
        sprintf(client->sockets->buffer, "%s,\"%s\",\"%s\"\n", LIST_THREAD,
        client->context->uuid_team, client->context->uuid_channel);
        return;
    }
    sprintf(client->sockets->buffer, "%s,\"%s\",\"%s\",\"%s\"\n", LIST_MESSAGE,
    client->context->uuid_team, client->context->uuid_channel,
    client->context->uuid_thread);
}

int list(client_t *client)
{
    if (!is_logged(client))
        return 0;
    send_message_list(client);
    return 1;
}