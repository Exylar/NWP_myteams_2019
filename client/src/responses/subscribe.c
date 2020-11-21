/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribe
*/

#include "error.h"
#include "libparse.h"
#include "logging_client.h"
#include "response.h"

void print_valid_subscribe(client_t *client)
{
    const char *end_ptr;
    char **array = parse_args(client->receive_command + 4,
    &end_ptr, PARSE_COMMA);

    if (array != NULL) {
        client_print_subscribed(array[0], array[1]);
        free_array(array);
    }
}

void print_subscribe(client_t *client)
{
    if (strstr(client->receive_command, "200")) {
        print_valid_subscribe(client);
        return;
    }
    if (strstr(client->receive_command, "404")) {
        print_unknown_error(client, TEAM_ERROR);
        return;
    }
    if (strstr(client->receive_command, "409")) {
        client_error_already_exist();
        return;
    }
    client_error_unauthorized();
}