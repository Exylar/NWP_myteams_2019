/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_client_list
*/

#include "client.h"
#include <stdlib.h>

void delete_client_list(struct client_list_s *list)
{
    free(list);
}
