/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_wait_for_action
*/

#include "server.h"
#include <errno.h>

static int do_select(fd_set *rset, fd_set *wset)
{
    int nselect = select(FD_SETSIZE, rset, wset, NULL, NULL);

    if (server_need_shutdown(GET) == true)
        return 1;
    if (nselect == -1)
        return -1;
    return 0;
}

static int server_exec_action(struct server_s *server,
    struct sclienthead *clients, fd_set *rset, fd_set *wset)
{
    struct client_s *client;

    STAILQ_FOREACH(client, clients, entries) {
        if (FD_ISSET(client->socket->fd, wset)) {
            write_to_client(client);
            FD_CLR(client->socket->fd, &server->wset);
        }
        if (!FD_ISSET(client->socket->fd, rset))
            continue;
        if (read_from_client(client) == -1)
            return -1;
    }
    return 0;
}

int server_wait_for_action(struct server_s *server, struct sclienthead *clients)
{
    fd_set rset = server->rset;
    fd_set wset = server->wset;
    int nselect = do_select(&rset, &wset);

    if (nselect != 0)
        return nselect;
    if (FD_ISSET(server->socket->fd, &rset)) {
        if (server_add_new_client(server, clients) == -1)
            return -1;
    }
    return server_exec_action(server, clients, &rset, &wset);
}
