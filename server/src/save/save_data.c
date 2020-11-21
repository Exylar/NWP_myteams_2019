/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save_data
*/

#include "save.h"

int save_data(struct suserhead *users, struct steamhead *teams)
{
    if (check_directory() == -1)
        return -1;
    if (save_users(users) == -1)
        return -1;
    if (save_teams(teams) == -1)
        return -1;
    return 0;
}