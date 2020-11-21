/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_socket
*/

#include "socket.h"
#include <stdlib.h>
#include <unistd.h>

void delete_socket(struct socket_s *socket)
{
    if (socket == NULL)
        return;
    close(socket->fd);
    free(socket->in);
    free(socket->out);
    free(socket);
}
