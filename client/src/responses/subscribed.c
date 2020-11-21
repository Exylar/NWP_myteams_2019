/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribed
*/

#include "error.h"
#include "libparse.h"
#include "logging_client.h"
#include "response.h"

void print_users_subscribed_teams(client_t *client)
{
    char **array;
    char *token;
    char *str;
    char *tofree;
    const char *end_ptr;

    tofree = str = strdup(client->receive_command + 4);
    while ((token = strsep(&str, ";")) != NULL) {
        if ((array = parse_args(token, &end_ptr, PARSE_COMMA)) != NULL)
            client_print_subscribed(array[0], array[1]);
        free_array(array);
    }
    free(tofree);
}

void print_subscribed(client_t *client)
{
    if (strcmp(client->receive_command, "200 \n") == 0)
        return;
    if (strstr(client->receive_command, "200")) {
        print_users_subscribed_teams(client);
    } else if (strstr(client->receive_command, "404"))
        print_unknown_error(client, TEAM_ERROR);
    else
        client_error_unauthorized();
}