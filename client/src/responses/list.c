/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list
*/

#include "error.h"
#include "libparse.h"
#include "logging_client.h"
#include "response.h"

void print_loop_teams(client_t *client)
{
    char **array;
    char *token;
    char *str;
    char *tofree;
    const char *end_ptr;

    tofree = str = strdup(client->receive_command + 4);
    while ((token = strsep(&str, ";")) != NULL) {
        if ((array = parse_args(token, &end_ptr, PARSE_COMMA)) != NULL) {
            client_print_teams(array[0], array[1], array[2]);
            free_array(array);
        }
    }
    free(tofree);
}

void print_loop_channel(client_t *client)
{
    char **array;
    char *token;
    char *str;
    char *tofree;
    const char *end_ptr;

    tofree = str = strdup(client->receive_command + 4);
    while ((token = strsep(&str, ";")) != NULL) {
        if ((array = parse_args(token, &end_ptr, PARSE_COMMA)) != NULL) {
            client_print_channel(array[0], array[1], array[2]);
            free_array(array);
        }
    }
    free(tofree);
}

void print_loop_thread(client_t *client)
{
    char **array;
    char *token;
    char *str;
    char *tofree;
    const char *end_ptr;

    tofree = str = strdup(client->receive_command + 4);
    while ((token = strsep(&str, ";")) != NULL) {
        if ((array = parse_args(token, &end_ptr, PARSE_COMMA)) != NULL) {
            client_print_thread(array[0], array[1], atoi(array[2]),
            array[3], array[4]);
            free_array(array);
        }
    }
    free(tofree);
}

void print_loop_replies(client_t *client)
{
    char **array;
    char *token;
    char *str;
    char *tofree;
    const char *end_ptr;

    tofree = str = strdup(client->receive_command + 4);
    while ((token = strsep(&str, ";")) != NULL) {
        if ((array = parse_args(token, &end_ptr, PARSE_COMMA)) != NULL) {
            client_thread_print_replies(array[0], array[1],
            atoi(array[2]), array[3]);
            free_array(array);
        }
    }
    free(tofree);
}

void print_list(client_t *client)
{
    if (strcmp(client->receive_command, "200 \n") == 0) {
        return;
    }
    if (!client->context->uuid_team && strstr(client->receive_command, "200"))
        return print_loop_teams(client);
    if (!client->context->uuid_channel
        && strstr(client->receive_command, "200"))
        return print_loop_channel(client);
    if (!client->context->uuid_thread && strstr(client->receive_command, "200"))
        return print_loop_thread(client);
    if (client->context->uuid_thread && strstr(client->receive_command, "200"))
        return print_loop_replies(client);
    error_uuid_context(client);
}