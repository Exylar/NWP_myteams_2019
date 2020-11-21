/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** new_server
*/

#include "server.h"

struct server_s *new_server(uint16_t port)
{
    struct server_s *server = malloc(sizeof(struct server_s));
    struct socket_s *socket;

    if (server == NULL)
        return NULL;
    socket = new_socket(port);
    if (socket == NULL)
        return free(server), NULL;
    server->socket = socket;
    FD_ZERO(&server->rset);
    FD_ZERO(&server->wset);
    FD_SET(server->socket->fd, &server->rset);
    return server;
}
