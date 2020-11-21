/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_command
*/

#include "logging_client.h"
#include "error.h"

const error_t unknown_error[NB_ERROR_COMMAND] = {
    {&client_error_unknown_user},
    {&client_error_unknown_team},
    {&client_error_unknown_channel},
    {&client_error_unknown_thread},
    {NULL},
};