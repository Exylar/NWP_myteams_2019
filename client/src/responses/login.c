/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "cli.h"
#include "libparse.h"
#include "logging_client.h"

void print_login(client_t *client)
{
    char **array;
    const char *end_ptr;

    if (strstr(client->receive_command, "200")) {
        array = parse_args(client->receive_command + 4, &end_ptr, PARSE_COMMA);
        if (array != NULL) {
            client->uuid = array[0];
            client->username = array[1];
            client->is_logged = 1;
            client_event_loggedin(client->uuid, client->username);
            free(array);
        }
    } else
        client_error_unauthorized();
}