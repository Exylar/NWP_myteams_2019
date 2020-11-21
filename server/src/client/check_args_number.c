/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** check_args_number
*/

#include "server.h"

bool check_args_number(char **params, int fd, size_t nb)
{
    if (my_array_len(params) < nb) {
        dprintf(fd, BAD_SYNTAX, "Wrong number of argument");
        return false;
    }
    return true;
}