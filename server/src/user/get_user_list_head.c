/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_user_list_head
*/

#include "user.h"

struct suserhead *get_user_list_head(void)
{
    static struct suserhead head = {};

    return &head;
}
