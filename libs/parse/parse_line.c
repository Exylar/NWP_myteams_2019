/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** parse_line
*/

#include "lib_free_array.c"
#include "libparse.h"
#include <stdlib.h>
#include <string.h>

static size_t lib_array_len(char **arr)
{
    size_t n = 0;

    while (*arr) {
        ++n;
        ++arr;
    }
    return n;
}

char **parse_line(
    const char *line, const char **end_ptr, struct parse_sep_s sep)
{
    size_t cmdlen = strcspn(line, " \t\n");
    size_t arraylen;
    char *cmd = strndup(line, cmdlen);
    char **array;

    array = parse_args(
        line + cmdlen + strspn(line + cmdlen, " \t"), end_ptr, sep);
    if (array == NULL || **end_ptr != '\n')
        return free(cmd), lib_free_array(array), NULL;
    arraylen = lib_array_len(array);
    array = realloc(array, sizeof(char *) * (arraylen + 2));
    for (int i = arraylen; i > 0; --i)
        array[i] = array[i - 1];
    array[0] = cmd;
    array[arraylen + 1] = NULL;
    return array;
}
