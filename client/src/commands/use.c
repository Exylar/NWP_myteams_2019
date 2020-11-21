/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** use
*/

#include "commands.h"
#include "consts.h"

int use(client_t *client)
{
    if (!is_logged(client))
        return 0;
    client->context->uuid_team = (client->nb_params >= 2) ?
strdup(client->parsed_command[1]) : NULL;
    client->context->uuid_channel = (client->nb_params >= 3) ?
strdup(client->parsed_command[2]) : NULL;
    client->context->uuid_thread = (client->nb_params >= 4) ?
strdup(client->parsed_command[3]) : NULL;
    return 1;
}