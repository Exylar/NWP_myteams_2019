/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info
*/

#include "error.h"
#include "libparse.h"
#include "logging_client.h"
#include "response.h"

void print_info_users(client_t *client)
{
    const char *end_ptr;
    char **array = parse_args(client->receive_command + 4,
    &end_ptr, PARSE_COMMA);

    if (array != NULL) {
        client_print_users(array[0], array[1], atoi(array[2]));
        free_array(array);
    }
}

void print_info_teams(client_t *client)
{
    const char *end_ptr;
    char **array = parse_args(client->receive_command + 4,
    &end_ptr, PARSE_COMMA);

    if (array != NULL) {
        client_print_team(array[0], array[1], array[2]);
        free_array(array);
    }
}

void print_info_channel(client_t *client)
{
    const char *end_ptr;
    char **array = parse_args(client->receive_command + 4,
    &end_ptr, PARSE_COMMA);

    if (array != NULL) {
        client_print_channel(array[0], array[1], array[2]);
        free_array(array);
    }
}

void print_info_thread(client_t *client)
{
    const char *end_ptr;
    char **array = parse_args(client->receive_command + 4,
    &end_ptr, PARSE_COMMA);

    if (array != NULL) {
        client_print_thread(array[0], array[1], atoi(array[2]),
        array[3], array[4]);
        free_array(array);
    }
}

void print_info(client_t *client)
{
    if (!client->context->uuid_team && strstr(client->receive_command, "200"))
        return print_info_users(client);
    if (!client->context->uuid_channel
        && strstr(client->receive_command, "200"))
        return print_info_teams(client);
    if (!client->context->uuid_thread &&
        strstr(client->receive_command, "200"))
        return print_info_channel(client);
    if (client->context->uuid_thread && strstr(client->receive_command, "200"))
        return print_info_thread(client);
    error_uuid_context(client);
}