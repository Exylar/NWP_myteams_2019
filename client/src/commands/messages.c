/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message
*/

#include "commands.h"
#include "consts.h"

int messages(client_t *client)
{
    if (!is_logged(client))
        return 0;
    if (!client->parsed_command[1]) {
        printf("Command send subscribe a user UUID\n");
        return 0;
    }
    else if (client->parsed_command[2]) {
        printf("Too many arguments\n");
        return 0;
    }
    sprintf(client->sockets->buffer, "%s \"%s\"\n", MESSAGE,
    client->parsed_command[1]);
    return 1;
}