/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_client
*/

#include "client.h"
#include <stdlib.h>

void delete_client(struct client_s *client)
{
    if (client == NULL)
        return;
    printf("%d is disconnecting\n", client->socket->fd);
    delete_socket(client->socket);
    free(client);
}
