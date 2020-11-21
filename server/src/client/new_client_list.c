/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** new_client_list
*/

#include "client.h"
#include <stdlib.h>

struct client_list_s *new_client_list(struct client_s *client)
{
    struct client_list_s *list = calloc(1, sizeof(struct client_list_s));

    list->client = client;
    return list;
}
