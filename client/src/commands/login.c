/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "myteams.h"
#include "commands.h"
#include "consts.h"
#include "error.h"

int login(client_t *client)
{
    if (client->parsed_command[1] == NULL) {
        printf("Command login need an username as parameter\n");
        return 0;
    } else if (client->parsed_command[2] != NULL) {
        printf("Too many arguments\n");
        return 0;
    } if (strlen(client->parsed_command[1]) > MAX_NAME_LENGTH) {
        error_message_parms("username", MAX_NAME_LENGTH);
        return 0;
    }
    sprintf(client->sockets->buffer, "%s \"%s\"\n", LOGIN,
    client->parsed_command[1]);
    return 1;
}