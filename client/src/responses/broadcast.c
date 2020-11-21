/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** broadcast
*/

#include "response.h"
#include "logging_client.h"
#include "libparse.h"

int broadcast_log(client_t *client)
{
    char **array;
    const char *end_ptr;

    if (strstr(client->receive_command, "LOGGEDIN")) {
        array = parse_args(client->receive_command + 4, &end_ptr, PARSE_COMMA);
        if (array != NULL) {
            client_event_loggedin(array[2], array[3]);
            free_array(array);
        }
        return 1;
    }
    if (strstr(client->receive_command, "LOGGEDOUT")) {
        array = parse_args(client->receive_command + 4, &end_ptr, PARSE_COMMA);
        if (array != NULL) {
            client_event_loggedout(array[2], array[3]);
            free_array(array);
        }
        return 1;
    }
    return 0;
}

int broadcast_message(client_t *client)
{
    char **array;
    const char *end_ptr;

    if (strstr(client->receive_command, "MP")) {
        array = parse_args(client->receive_command + 4, &end_ptr, PARSE_COMMA);
        if (array != NULL) {
            client_event_private_message_received(array[2], array[3]);
            free_array(array);
        }
        return 1;
    }
    if (strstr(client->receive_command, "COMMENT")) {
        array = parse_args(client->receive_command + 4, &end_ptr, PARSE_COMMA);
        if (array != NULL) {
            client_event_thread_message_received(array[2], array[3], array[4],
            array[5]);
            free_array(array);
        }
        return 1;
    }
    return 0;
}

void broadcast_create2(char **array)
{
    if (array != NULL) {
        client_event_thread_created(array[2], array[3], atoi(array[4]),
        array[5], array[6]);
        free_array(array);
    }
}

int broadcast_create(client_t *client)
{
    const char *end_ptr;
    char **array = parse_args(client->receive_command + 4, &end_ptr,
    PARSE_COMMA);

    if (strstr(client->receive_command, "TEAM")) {
        if (array != NULL) {
            client_event_team_created(array[2], array[3], array[4]);
            free_array(array);
        } return 1;
    } if (strstr(client->receive_command, "CHANNEL")) {
        if (array != NULL) {
            client_event_channel_created(array[2], array[3], array[4]);
            free_array(array);
        } return 1;
    }
    if (strstr(client->receive_command, "THREAD")) {
        broadcast_create2(array);
        return 1;
    }
    free_array(array);
    return 0;
}

void broadcast(client_t *client)
{
    if (broadcast_log(client))
        return;
    if (broadcast_message(client))
        return;
    broadcast_create(client);
}