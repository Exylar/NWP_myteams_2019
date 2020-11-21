/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** write_to_client
*/

#include "server.h"

void write_to_client(struct client_s *client)
{
    size_t len = strlen(client->socket->out);

    write(client->socket->fd, client->socket->out, len);
    memset(client->socket->out, 0, len);
    client->socket->need_write = false;
}
