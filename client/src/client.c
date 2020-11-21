/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** client
*/

#include "cli.h"

static int do_select(int fdsocket, fd_set *read_fds, fd_set *write_fds)
{
    int nselect = select(fdsocket + 1, read_fds, write_fds, NULL, NULL);

    if (client_need_shutdown(false, false) == true)
        return 1;
    if (nselect == -1)
        exit(84);
    return 0;
}

static void select_input(client_t *client, fd_set *read_fds, fd_set *write_fds)
{
    if (client->sockets->need_write == true)
        FD_SET(client->fdsocket, write_fds);
    if (do_select(client->fdsocket, read_fds, write_fds) == 1)
        return;
    if (FD_ISSET(client->fdsocket, write_fds)) {
        dprintf(client->fdsocket, "%s", client->sockets->buffer);
        client->sockets->need_write = false;
        memset(client->sockets->buffer, 0, MAX_COMMAND_LENGTH + 1);
        FD_CLR(client->fdsocket, write_fds);
    }
    if (FD_ISSET(client->fdsocket, read_fds))
        read_receive_command(client);
    if (FD_ISSET(client->sockets->fd_in, read_fds))
        read_input_command(client);
}

void client(char *ip, int port, int fdsocket)
{
    client_t *client = init_client_struct(ip, port, fdsocket);
    init_fd_struct(client);
    fd_set read_fds;
    fd_set write_fds;
    setbuf(stdout, NULL);

    read_receive_command(client);
    while (client_need_shutdown(false, false) == false) {
        FD_ZERO(&read_fds);
        FD_ZERO(&write_fds);
        FD_SET(client->sockets->fd_in, &read_fds);
        FD_SET(client->fdsocket, &read_fds);
        select_input(client, &read_fds, &write_fds);
    }
    free_client(client);
}