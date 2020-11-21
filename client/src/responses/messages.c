/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** messages
*/

#include "error.h"
#include "libparse.h"
#include "logging_client.h"
#include "response.h"

void print_list_message(client_t *client)
{
    char **array;
    char *token;
    char *str;
    char *tofree;
    const char *end_ptr;

    tofree = str = strdup(client->receive_command + 4);
    while ((token = strsep(&str, ";")) != NULL) {
        if ((array = parse_args(token, &end_ptr, PARSE_COMMA)) != NULL)
            client_private_message_print_messages(array[0], atoi(array[1]),
            array[2]);
        free_array(array);
    }
    free(tofree);
}

void print_messages(client_t *client)
{
    if (strcmp(client->receive_command, "200 \0") == 0) {
        return;
    }
    if (strstr(client->receive_command, "200"))
        print_list_message(client);
    else if (strstr(client->receive_command, "404"))
        print_unknown_error(client, USER_ERROR);
    else
        client_error_unauthorized();
}