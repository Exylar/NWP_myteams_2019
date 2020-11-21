/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** accept_connection
*/

#include "myteams.h"
#include "socket.h"
#include <stdlib.h>
#include <sys/select.h>

struct socket_s *accept_connection(int fd)
{
    struct socket_s *sock = malloc(sizeof(struct socket_s));
    socklen_t len = sizeof(struct sockaddr_in);

    if (sock == NULL)
        return 0;
    sock->fd = accept(fd, (struct sockaddr *)&sock->name, &len);
    if (sock->fd == -1 || sock->fd >= FD_SETSIZE)
        return NULL;
    sock->in = calloc(MAX_COMMAND_LENGTH + 1, sizeof(char));
    sock->out = calloc(MAX_COMMAND_LENGTH + 1, sizeof(char));
    if (sock->in == NULL || sock->out == NULL)
        return NULL;
    sock->need_write = false;
    printf("%d is connected\n", sock->fd);
    return sock;
}
