/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include "myteams.h"
#include "server.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    struct server_s *server;
    uint16_t port;
    char *ptr;
    int ret = MYTEAMS_SUCCESS;

    if (argc != 2 || *argv[1] == '\0')
        return MYTEAMS_FAILURE;
    port = strtol(argv[1], &ptr, 10);
    if (*ptr != '\0')
        return MYTEAMS_FAILURE;
    server = new_server(port);
    if (server == NULL)
        return MYTEAMS_FAILURE;
    if (server_loop(server) == -1) {
        perror(NULL);
        ret = MYTEAMS_FAILURE;
    }
    delete_server(server);
    return ret;
}
