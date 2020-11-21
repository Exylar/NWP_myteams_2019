/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** exec_client_cmd
*/

#include "commands.h"

void exec_client_cmd(struct client_s *client, char **args)
{
    struct suserhead *userhead = get_user_list_head();
    struct steamhead *teamhead = get_team_list_head();
    size_t arg_count = my_array_len(args);

    if (args[0] == NULL)
        return;
    for (int i = 0; CMDS[i].mnemonic != NULL; ++i) {
        if (strcasecmp(args[0], CMDS[i].mnemonic) != 0)
            continue;
        if (CMDS[i].must_be_logged_in == true && client->logged_in == false)
            return cprintf(client, NOT_CONNECTED);
        if (arg_count < CMDS[i].arg_nb)
            return cprintf(client, BAD_SYNTAX, "Wrong number of argument");
        return CMDS[i].fct(client, userhead, teamhead, args);
    }
    cprintf(client, INVALID_CMD);
}
