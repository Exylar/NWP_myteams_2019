/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_checkup_clients
*/

#include "server.h"

static void remove_linked_user(struct client_s *client)
{
    char buffer[UUID_STR_LEN] = {};
    struct client_list_s *list;
    struct user_s *user;

    if (client->logged_in == false)
        return;
    user = find_user_by_uuid(get_user_list_head(), client->uuid);
    if (user == NULL)
        return;
    list = find_client_list_by_client(&user->clients, client);
    if (list == NULL)
        return;
    STAILQ_REMOVE(&user->clients, list, client_list_s, entries);
    delete_client_list(list);
    uuid_unparse(user->uuid, buffer);
    printf("Unlinked client %d from user %s\n", client->socket->fd, buffer);
}

void server_checkup_clients(
    struct server_s *server, struct sclienthead *clients)
{
    struct client_s *curr = STAILQ_FIRST(clients);
    struct client_s *next;

    while (curr != NULL) {
        next = STAILQ_NEXT(curr, entries);
        if (curr->socket->need_write == true)
            FD_SET(curr->socket->fd, &server->wset);
        if (curr->need_logout == true)
            FD_CLR(curr->socket->fd, &server->rset);
        if (curr->need_logout == true && curr->socket->need_write == false) {
            remove_linked_user(curr);
            STAILQ_REMOVE(clients, curr, client_s, entries);
            delete_client(curr);
        }
        curr = next;
    }
}
