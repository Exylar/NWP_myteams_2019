/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** help
*/

#include "commands.h"
#include "consts.h"

int logout(client_t *client)
{
    if (client->parsed_command[1]) {
        printf("Too many arguments\n");
        return 0;
    }
    sprintf(client->sockets->buffer, "%s\n", LOGOUT);
    return 1;
}