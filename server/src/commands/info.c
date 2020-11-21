/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info
*/

#include "server.h"
#include "commands.h"

void info_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params)
{
    size_t arg_count = my_array_len(params);

    if (params[1] == NULL)
        return;
    for (int i = 0; INFO_CMDS[i].mnemonic != NULL; ++i) {
        if (strcasecmp(params[1], INFO_CMDS[i].mnemonic) != 0)
            continue;
        if (arg_count < INFO_CMDS[i].arg_nb)
            return cprintf(client, BAD_SYNTAX, "Wrong number of argument");
        return INFO_CMDS[i].fct(client, users, teams, params);
    }
    cprintf(client, INVALID_CMD);
}
