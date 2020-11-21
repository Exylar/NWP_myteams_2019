/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** socket
*/

#ifndef SOCKET_H_
#define SOCKET_H_

#include <netinet/in.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/socket.h>

struct socket_s {
    int fd; ///< Socket file descriptor
    struct sockaddr_in name; ///< Socket name
    char *in; ///< Read buffer
    char *out; ///< Write buffer
    bool need_write; ///< True if there are characters to write
};

struct socket_s *new_socket(uint16_t port);
void delete_socket(struct socket_s *socket);
struct socket_s *accept_connection(int fd);

#endif /* !SOCKET_H_ */
