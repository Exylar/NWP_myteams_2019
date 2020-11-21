/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** new_client
*/

#include "client.h"
#include <string.h>
#include <stdlib.h>

struct client_s *new_client(void)
{
    struct client_s *client = malloc(sizeof(struct client_s));

    if (client == NULL)
        return NULL;
    memset(client, 0, sizeof(struct client_s));
    return client;
}
