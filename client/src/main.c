/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** client
*/

#include "cli.h"
#include "logging_client.h"

static int usage(void)
{
    printf("USAGE:\t./myteams_cli ip port\n");
    return 84;
}

static int help(void)
{
    usage();
    printf("\tip\t is the server ip address on which the"
    "server socket listens\n");
    printf("\tport\t is the port number on which the server"
    "socket listens\n");
    return 0;
}

int create_socket(char *ip, int port)
{
    int fdsocket = 0;

    fdsocket = connection_to_socket(ip, port);
    if (fdsocket == -1) {
        printf("Error: Impossible to connect to socket\n");
        exit(EXIT_FAILURE);
    }
    return fdsocket;
}

int main(int argc, char **argv)
{
    int opt;
    int fdsocket = -1;

    opt = getopt(argc, argv, "help");
    if (opt == 'h') {
        return help();
    }
    else if (argc != 3) {
        return usage();
    }
    fdsocket = create_socket(argv[1], atoi(argv[2]));
    if (redirect_signals() == -1)
        exit(84);
    client(argv[1], atoi(argv[2]), fdsocket);
    return 0;
}