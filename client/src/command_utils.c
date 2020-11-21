/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_utils
*/

#include "cli.h"
#include "libparse.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

int get_number_paramters(char **array)
{
    int i = 0;

    for (i = 0; array[i] != NULL; i++);
    return i;
}