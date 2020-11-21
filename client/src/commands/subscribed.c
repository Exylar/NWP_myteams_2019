/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "commands.h"
#include "consts.h"

int subscribed(client_t *client)
{
    if (!is_logged(client))
        return 0;
    if (client->nb_params >= 3) {
        printf("Too many arguments\n");
        return 0;
    }
    if (client->parsed_command[1] == NULL)
        sprintf(client->sockets->buffer, "%s\n", SUBSCRIBED);
    else
        sprintf(client->sockets->buffer, "%s \"%s\"\n", SUBSCRIBED,
        client->parsed_command[1]);
    return 1;
}