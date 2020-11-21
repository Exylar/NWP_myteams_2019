/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** noop
*/

#include "commands.h"

void noop_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params)
{
    printf(
        "%d: %p %p", client->socket->fd, users->stqh_first, teams->stqh_first);
    for (int i = 0; params[i] != NULL; ++i)
        printf(" '%s'", params[i]);
    printf("\n");
    cprintf(client, "200 NOOP\n");
}
