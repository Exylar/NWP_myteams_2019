/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "response.h"
#include "logging_client.h"
#include "error.h"

void print_send(client_t *client)
{
    if (strstr(client->receive_command, "200"))
        printf("Message sent\n");
    else if (strstr(client->receive_command, "404"))
        print_unknown_error(client, USER_ERROR);
    else
        client_error_unauthorized();
}
