/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** find_client_list_by_client
*/

#include "client.h"

struct client_list_s *find_client_list_by_client(
    struct sclientlisthead *head, struct client_s *client)
{
    struct client_list_s *list;

    STAILQ_FOREACH(list, head, entries)
    {
        if (list->client == client)
            return list;
    }
    return NULL;
}
