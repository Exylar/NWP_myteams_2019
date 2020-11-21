/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "myteams.h"
#include "commands.h"
#include "consts.h"
#include "error.h"

static int check_arguemnts_is_valid(client_t *client)
{
    if (!client->parsed_command[1]) {
        return error_commands("Command set need an user UUID\n");
    } if (!client->parsed_command[2]) {
        return error_commands("Command sent need a message\n");
    } else if (client->parsed_command[3]) {
        return error_commands("Too many arguments\n");
    } if (strlen(client->parsed_command[2]) > MAX_BODY_LENGTH) {
        return error_message_parms("message", MAX_BODY_LENGTH);
    }
    return 1;
}

int send_cmd(client_t *client)
{
    if (!is_logged(client))
        return 0;
    if (!check_arguemnts_is_valid(client))
        return 0;
    sprintf(client->sockets->buffer, "%s \"%s\",\"%s\"\n", SEND,
    client->parsed_command[1],
    client->parsed_command[2]);
    return 1;
}