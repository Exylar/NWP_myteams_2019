/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "myteams.h"
#include "commands.h"
#include "consts.h"
#include "error.h"

int check_command_with_context(client_t *client)
{
    if (client->context->uuid_thread) {
        if (client->parsed_command[2]) {
            return error_commands("Too many arguments\n");
        } else if (!client->parsed_command[1]) {
            return error_commands("/create need one argument\n");
        }
    } else {
        if (client->parsed_command[3]) {
            return error_commands("Too many arguments\n");
        } else if (!client->parsed_command[2]) {
            return error_commands("/create need two argument\n");
        }
    }
    return 1;
}

int check_length_params(client_t *client)
{
    if (!client->context->uuid_team || !client->context->uuid_channel) {
        if (strlen(client->parsed_command[1]) > MAX_NAME_LENGTH) {
            return error_message_parms("name", MAX_NAME_LENGTH);
        } else if (strlen(client->parsed_command[2]) >
        MAX_DESCRIPTION_LENGTH) {
            return error_message_parms("desc", MAX_DESCRIPTION_LENGTH);
        }
    } else if (!client->context->uuid_thread) {
        if (strlen(client->parsed_command[1]) > MAX_NAME_LENGTH) {
            return error_message_parms("title", MAX_NAME_LENGTH);
        } else if (strlen(client->parsed_command[2]) > MAX_BODY_LENGTH) {
            return error_message_parms("message", MAX_BODY_LENGTH);
        }
    } else {
        if (strlen(client->parsed_command[1]) > MAX_BODY_LENGTH) {
            return error_message_parms("message", MAX_BODY_LENGTH);
        }
    }
    return 1;
}

void send_message_create(client_t *client)
{
    if (!client->context->uuid_team) {
        sprintf(client->sockets->buffer, "%s,\"%s\",\"%s\"\n", CREATE_TEAM,
        client->parsed_command[1], client->parsed_command[2]);
        return;
    } if (!client->context->uuid_channel) {
        sprintf(client->sockets->buffer, "%s,\"%s\",\"%s\",\"%s\"\n",
        CREATE_CHANNEL, client->context->uuid_team, client->parsed_command[1],
        client->parsed_command[2]);
        return;
    } if (!client->context->uuid_thread) {
        sprintf(client->sockets->buffer, "%s,\"%s\",\"%s\",\"%s\",\"%s\"\n",
        CREATE_THREAD, client->context->uuid_team,
        client->context->uuid_channel, client->parsed_command[1],
        client->parsed_command[2]);
        return;
    }
    sprintf(client->sockets->buffer, "%s,\"%s\",\"%s\",\"%s\",\"%s\"\n",
    CREATE_MESSAGE, client->context->uuid_team, client->context->uuid_channel,
    client->context->uuid_thread, client->parsed_command[1]);
}

int create(client_t *client)
{
    if (!is_logged(client))
        return 0;
    if (!check_command_with_context(client))
        return 0;
    if (!check_length_params(client))
        return 0;
    send_message_create(client);
    return 1;
}