/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_add_new_client
*/

#include "server.h"

int server_add_new_client(struct server_s *server, struct sclienthead *clients)
{
    struct client_s *client = new_client();

    if (client == NULL)
        return -1;
    client->socket = accept_connection(server->socket->fd);
    if (client->socket == NULL)
        return -1;
    cprintf(client, CONNECTED);
    FD_SET(client->socket->fd, &server->rset);
    FD_SET(client->socket->fd, &server->wset);
    STAILQ_INSERT_TAIL(clients, client, entries);
    return 0;
}
