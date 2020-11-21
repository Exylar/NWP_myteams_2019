/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** loaders
*/

#include "load.h"

const struct load_fct_s TEAM_LOADERS[] = {
    LOADER(team, 4),
    LOADER(sub, 3),
    LOADER(channel, 5),
    LOADER(thread, 8),
    LOADER(comment, 7),
    LOADER_END
};

const struct load_fct_s USER_LOADERS[] = {
    LOADER(user, 3),
    LOADER(dm, 3),
    LOADER(message, 6),
    LOADER_END
};
