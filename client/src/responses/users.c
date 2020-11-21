/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "libparse.h"
#include "logging_client.h"
#include "response.h"

void print_list_users(client_t *client)
{
    char **array;
    char *token;
    char *str;
    char *tofree;
    const char *end_ptr;

    tofree = str = strdup(client->receive_command + 4);
    while ((token = strsep(&str, ";")) != NULL) {
        if ((array = parse_args(token, &end_ptr, PARSE_COMMA)) != NULL)
            client_print_users(array[0], array[1], atoi(array[2]));
        free_array(array);
    }
    free(tofree);
}

void print_users(client_t *client)
{
    if (strcmp(client->receive_command, "200 \n") == 0) {
        return;
    }
    if (strstr(client->receive_command, "200")) {
        print_list_users(client);
        return;
    }
    client_error_unauthorized();
}