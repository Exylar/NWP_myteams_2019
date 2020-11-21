/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "error.h"
#include "libparse.h"
#include "logging_client.h"
#include "response.h"

void print_team_create(client_t *client)
{
    const char *end_ptr;
    char **array = parse_args(client->receive_command + 4, &end_ptr,
    PARSE_COMMA);

    if (array != NULL) {
        client_print_team_created(array[0], array[1], array[2]);
        free_array(array);
    }
}

void print_channel_create(client_t *client)
{
    const char *end_ptr;
    char **array = parse_args(client->receive_command + 4, &end_ptr,
    PARSE_COMMA);

    if (array != NULL) {
        client_print_channel_created(array[0], array[1], array[2]);
        free_array(array);
    }
}

void print_thread_create(client_t *client)
{
    const char *end_ptr;
    char **array = parse_args(client->receive_command + 4, &end_ptr,
    PARSE_COMMA);

    if (array != NULL) {
        client_print_thread_created(array[0], array[1], atoi(array[2]),
        array[3], array[4]);
        free_array(array);
    }
}

void print_replies_create(client_t *client)
{
    const char *end_ptr;
    char **array = parse_args(client->receive_command + 4, &end_ptr,
    PARSE_COMMA);

    if (array != NULL) {
        client_print_reply_created(array[0], array[1], atoi(array[2]),
        array[3]);
        free_array(array);
    }
}

void print_create(client_t *client)
{
    if (!client->context->uuid_team && strstr(client->receive_command, "201"))
        return print_team_create(client);
    if (!client->context->uuid_channel
        && strstr(client->receive_command, "201"))
        return print_channel_create(client);
    if (!client->context->uuid_thread && strstr(client->receive_command, "201"))
        return print_thread_create(client);
    if (client->context->uuid_thread && strstr(client->receive_command, "201"))
        return print_replies_create(client);
    error_uuid_context(client);
}