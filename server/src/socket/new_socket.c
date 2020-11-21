/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** new_socket
*/

#include "socket.h"
#include <stdlib.h>
#include <string.h>

static int make_socket(struct socket_s *sock, uint16_t port)
{
    int fd = socket(PF_INET, SOCK_STREAM, 0);
    socklen_t len = sizeof(struct sockaddr_in);
    int val = 1;

    if (fd == -1)
        return -1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int)) == -1)
        return -1;
    sock->name.sin_family = AF_INET;
    sock->name.sin_port = htons(port);
    sock->name.sin_addr.s_addr = INADDR_ANY;
    if (bind(fd, (struct sockaddr *)&sock->name, len) == -1)
        return -1;
    if (listen(fd, SOMAXCONN) == -1)
        return -1;
    sock->fd = fd;
    if (getsockname(fd, (struct sockaddr *)&sock->name, &len) == -1)
        return -1;
    return 0;
}

struct socket_s *new_socket(uint16_t port)
{
    struct socket_s *new = malloc(sizeof(struct socket_s));

    if (new == NULL)
        return NULL;
    memset(new, 0, sizeof(struct socket_s));
    if (make_socket(new, port) == -1) {
        free(new);
        return NULL;
    }
    return new;
}
