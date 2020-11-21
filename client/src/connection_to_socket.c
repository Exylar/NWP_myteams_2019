/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** connection_to_socket
*/

#include <netinet/in.h>
#include <string.h>

static void init_struct_address(struct sockaddr_in *address, char *ip, int port)
{
    (void)ip;
    (*address).sin_family = AF_INET;
    (*address).sin_addr.s_addr = INADDR_ANY;
    (*address).sin_port = htons(port);
}

int connection_to_socket(char *ip, int port)
{
    int new_socket;
    struct sockaddr_in address;

    if ((new_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;
    memset(&address, '\0', sizeof(address));
    init_struct_address(&address, ip, port);
    if (connect(new_socket, (struct sockaddr *)&address, sizeof(address)))
        return -1;
    return new_socket;
}