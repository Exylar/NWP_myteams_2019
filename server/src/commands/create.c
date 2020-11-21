/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "commands.h"
#include <strings.h>

void create_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params)
{
    size_t arg_count = my_array_len(params);

    if (params[1] == NULL)
        return;
    for (int i = 0; CREATE_CMDS[i].mnemonic != NULL; ++i) {
        if (strcasecmp(params[1], CREATE_CMDS[i].mnemonic) != 0)
            continue;
        if (arg_count < CREATE_CMDS[i].arg_nb)
            return cprintf(client, BAD_SYNTAX, "Wrong number of argument");
        return CREATE_CMDS[i].fct(client, users, teams, params);
    }
    cprintf(client, INVALID_CMD);
}
