/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_array_len
*/

#include "server.h"

size_t my_array_len(void *array)
{
    char **oui = array;
    size_t len = 0;

    for (;oui[len]; len++);
    return len;
}