/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout
*/

#include "response.h"
#include "logging_client.h"

void print_logout(client_t *client)
{
    if (strstr(client->receive_command, "200")) {
        if (client->is_logged) {
            client_event_loggedout(client->uuid, client->username);
            free(client->uuid);
            free(client->username);
        }
        client->is_logged = 0;
        client->uuid = NULL;
        client->username = NULL;
        client_need_shutdown(true, true);
    }
}