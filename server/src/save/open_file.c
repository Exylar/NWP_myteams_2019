/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** open_file
*/

#include "save.h"

FILE *open_file(const char *path)
{
    FILE *file;

    file = fopen(path, "w");
    if (file == NULL) {
        printf("Cannot save data.\n");
        return NULL;
    }
    return file;
}