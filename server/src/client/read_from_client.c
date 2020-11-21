/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** read_from_client
*/

#include "server.h"
#include <string.h>
#include <unistd.h>

int read_from_client(struct client_s *client)
{
    char cmd[MAX_COMMAND_LENGTH + 1];
    ssize_t nread = read(client->socket->fd, cmd, MAX_COMMAND_LENGTH);
    ssize_t len = strlen(client->socket->in);

    if (nread == -1)
        return -1;
    if (nread == 0 || len + nread > MAX_COMMAND_LENGTH) {
        client->need_logout = true;
        client->socket->need_write = false;
        return 0;
    }
    cmd[nread] = '\0';
    strcat(client->socket->in, cmd);
    analyse_client_cmd(client);
    return 0;
}
