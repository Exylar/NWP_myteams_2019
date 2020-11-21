/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** lib_free_array
*/

#include <stdlib.h>

static void lib_free_array(char **arr)
{
    if (arr == NULL)
        return;
    for (size_t n = 0; arr[n]; ++n)
        free(arr[n]);
    free(arr);
}
