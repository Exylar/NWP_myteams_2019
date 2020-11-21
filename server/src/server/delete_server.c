/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_server
*/

#include "server.h"

void delete_server(struct server_s *server)
{
    if (server == NULL)
        return;
    delete_socket(server->socket);
    free(server);
}
