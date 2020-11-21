/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_need_shutdown
*/

#include "server.h"

bool server_need_shutdown(bool flag, bool value)
{
    static bool need_shutdown = false;

    if (flag == true)
        need_shutdown = value;
    return need_shutdown;
}
