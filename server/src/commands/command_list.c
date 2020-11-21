/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_list
*/

#include "commands.h"

const struct command_s CMDS[] = {
    CMD(create, true, 4),
    CMD(info, true, 2),
    CMD(list, true, 2),
    CMD(login, false, 2),
    CMD(logout, false, 1),
    CMD(noop, false, 1),
    CMD(send, true, 3),
    CMD(user, true, 2),
    CMD(users, true, 1),
    CMD(subscribe, true, 2),
    CMD(unsubscribe, true, 2),
    CMD(subscribed, true, 1),
    CMD(messages, true, 1),
    CMD_END
};

const struct command_s CREATE_CMDS[] = {
    CREATE_CMD(team, 4),
    CREATE_CMD(channel, 5),
    CREATE_CMD(thread, 6),
    CREATE_CMD(comment, 6),
    CMD_END
};

const struct command_s INFO_CMDS[] = {
    INFO_CMD(user, 2),
    INFO_CMD(team, 3),
    INFO_CMD(channel, 4),
    INFO_CMD(thread, 5),
    CMD_END
};

const struct command_s LIST_CMDS[] = {
    LIST_CMD(team, 2),
    LIST_CMD(channel, 3),
    LIST_CMD(thread, 4),
    LIST_CMD(comment, 5),
    CMD_END
};
