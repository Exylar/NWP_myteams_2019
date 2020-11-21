/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_line
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

char *get_next_line(FILE *fstream)
{
    char *line = NULL;
    size_t n = 0;
    ssize_t n_read;

    n_read = getline(&line, &n, fstream);
    if (n_read == -1) {
        free(line);
        return NULL;
    }
    return line;
}
