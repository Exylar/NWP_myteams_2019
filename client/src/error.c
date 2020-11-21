/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** error
*/

#include "cli.h"
#include "logging_client.h"
#include "error.h"
#include "libparse.h"

int error_message_parms(char *type, int value)
{
    printf("A %s can't take over %d characters\n", type, value);
    return 0;
}

int error_commands(char *message)
{
    printf("%s", message);
    return 0;
}

void print_unknown_error(client_t *client, enum type_error type)
{
    const char *end_ptr;
    char **array;

    array = parse_args(client->receive_command + 4, &end_ptr, PARSE_COMMA);
    if (array != NULL) {
        unknown_error[type].func(array[2]);
        free_array(array);
    }
    return;
}

void error_uuid_context(client_t *client)
{
    if (strstr(client->receive_command, "404") &&
    strstr(client->receive_command, "team")) {
        print_unknown_error(client, TEAM_ERROR);
        return;
    }
    if (strstr(client->receive_command, "404") &&
    strstr(client->receive_command, "channel")) {
        print_unknown_error(client, CHANNEL_ERROR);
        return;
    }
    if (strstr(client->receive_command, "404") &&
    strstr(client->receive_command, "thread")) {
        print_unknown_error(client, THREAD_ERROR);
        return;
    }
    client_error_unauthorized();
    return;
}