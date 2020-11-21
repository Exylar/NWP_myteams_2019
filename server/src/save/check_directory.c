/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** check_directory
*/

#include "save.h"

int check_directory(void)
{
    struct stat buffer = {0};

    if (stat(SAVE_DIR_PATH, &buffer) == -1) {
        return mkdir(SAVE_DIR_PATH, 0775);
    }
    return 0;
}