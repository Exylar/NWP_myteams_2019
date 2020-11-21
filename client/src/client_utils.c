/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_utils
*/

#include "cli.h"

client_t *init_client_struct(char *ip, int port, int fdsocket)
{
    client_t *client = malloc(sizeof(client_t));
    context_t *context = malloc(sizeof(context_t));

    client->cmd_buffer = calloc(sizeof(char), MAX_COMMAND_LENGTH + 1);
    context->uuid_channel = NULL;
    context->uuid_team = NULL;
    context->uuid_thread = NULL;
    STAILQ_INIT(&client->head);
    client->fdsocket = fdsocket;
    client->ip = ip;
    client->port = port;
    client->is_logged = 0;
    client->context = context;
    return client;
}

void init_fd_struct(client_t *client)
{
    sockets_t *sockets = malloc(sizeof(sockets_t));

    sockets->fd_in = 0;
    sockets->need_write = false;
    client->sockets = sockets;
}

int is_logged(client_t *client)
{
    if (client->is_logged)
        return 1;
    else {
        printf("User must be connected to use this command\n");
        return 0;
    }
}

void free_client(client_t *client)
{
    free(client->sockets);
    if (client->context->uuid_team)
        free(client->context->uuid_team);
    if (client->context->uuid_channel)
        free(client->context->uuid_channel);
    if (client->context->uuid_thread)
        free(client->context->uuid_thread);
    free(client->context);
    free(client->cmd_buffer);
    free(client);
}