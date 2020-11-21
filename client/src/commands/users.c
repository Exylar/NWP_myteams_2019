/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "commands.h"
#include "consts.h"

int users(client_t *client)
{
    if (!is_logged(client))
        return 0;
    if (client->parsed_command[1]) {
        printf("Too many arguments\n");
        return 0;
    }
    sprintf(client->sockets->buffer, "%s\n", USERS);
    return 1;
}