/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** parse_args
*/

#include "lib_free_array.c"
#include "libparse.h"
#include "swap.c"
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

static char **add_element_to_array(
    char **array, const char *begin, const char *end)
{
    size_t n = lib_array_len(array);

    array = realloc(array, sizeof(char *) * (n + 2));
    if (array == NULL)
        return NULL;
    array[n] = strndup(begin, end - begin);
    array[n + 1] = NULL;
    return array;
}

static char *get_quote_end(const char *str, const char *sep)
{
    char *end1 = strstr(str, sep);
    char *end2 = strstr(str, "\"\n");
    char *end3 = strrchr(str, '"');

    if (end3 != NULL && end3[1] != '\0')
        end3 = NULL;
    if (end1 > end2)
        swap(&end1, &end2);
    if (end1 > end3)
        swap(&end1, &end3);
    if (end2 > end3)
        swap(&end2, &end3);
    if (end1 != NULL)
        return end1;
    if (end2 != NULL)
        return end2;
    return end3;
}

char **parse_args(const char *cmd, const char **end_ptr, struct parse_sep_s sep)
{
    char **array = malloc(sizeof(char *));

    *array = NULL;
    while (1) {
        if (*cmd == '\0' || *cmd == '\n') {
            *end_ptr = cmd;
            return array;
        } else if (*cmd == '\"') {
            *end_ptr = get_quote_end(cmd + 1, sep.quote);
            if (*end_ptr == NULL)
                break;
            array = add_element_to_array(array, cmd + 1, *end_ptr);
            ++(*end_ptr);
        } else {
            *end_ptr = cmd + strcspn(cmd, sep.skip);
            array = add_element_to_array(array, cmd, *end_ptr);
        }
        cmd = *end_ptr + (**end_ptr == sep.c ? 1 : 0);
    }
    lib_free_array(array);
    return NULL;
}
