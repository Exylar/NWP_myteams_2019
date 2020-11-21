/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** fetch_team_list
*/

#include "team.h"

struct steamhead *get_team_list_head(void)
{
    static struct steamhead head = {};

    return &head;
}
