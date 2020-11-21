/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_command
*/

#include "commands.h"
#include "consts.h"
#include "response.h"

const command_t my_commands[NB_COMMANDS] = {
    {"/help", &help_command},
    {"/use", &use},
    {"/create", &create},
    {"/info", &info},
    {"/list", &list},
    {"/login", &login},
    {"/logout", &logout},
    {"/messages", &messages},
    {"/send", &send_cmd},
    {"/subscribe", &subscribe},
    {"/subscribed", &subscribed},
    {"/unsubscribe", &unsubscribe},
    {"/user", &user},
    {"/users", &users},
    {NULL, NULL}
};

const command_receive_t receive_commands[NB_RECEIVE_COMMANDS] = {
    {"/create", &print_create},
    {"/info", &print_info},
    {"/list", &print_list},
    {"/login", &print_login},
    {"/logout", &print_logout},
    {"/messages", &print_messages},
    {"/send", &print_send},
    {"/subscribe", &print_subscribe},
    {"/subscribed", &print_subscribed},
    {"/unsubscribe", &print_unsubscribe},
    {"/user", &print_user},
    {"/users", &print_users},
    {NULL, NULL}
};