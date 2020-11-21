/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_data
*/

#include "libparse.h"
#include "load.h"
#include <strings.h>
#include <sys/mman.h>

static void analyse_line(
    const struct load_fct_s *loaders, void *head, char **args)
{
    if (args[0] == NULL)
        return;
    for (int i = 0; loaders[i].mnemonic != NULL; ++i) {
        if (strcasecmp(loaders[i].mnemonic, args[0]) != 0)
            continue;
        if (my_array_len(args) == loaders[i].arg_nb)
            loaders[i].fct(head, args);
        return;
    }
}

static void read_save_file(
    const char *file, const struct load_fct_s *loaders, void *head)
{
    const char *end_ptr = NULL;
    char **args;

    while ((args = parse_args(file, &end_ptr, PARSE_COMMA)) != NULL) {
        analyse_line(loaders, head, args);
        free_array(args);
        file = end_ptr + 1;
        if (*end_ptr == '\0')
            break;
    }
}

static int load_file(
    const char *filepath, const struct load_fct_s *loaders, void *head)
{
    off_t size = 0;
    const char *file = map_file(filepath, &size);

    if (file == NULL)
        return -1;
    read_save_file(file, loaders, head);
    munmap((void *)file, size);
    return 0;
}

void load_data(struct suserhead *users, struct steamhead *teams)
{
    STAILQ_INIT(users);
    STAILQ_INIT(teams);
    if (load_file(SAVE_USERS_PATH, USER_LOADERS, users) == -1)
        puts("No user data was found (file empty or inexistant).");
    if (load_file(SAVE_TEAMS_PATH, TEAM_LOADERS, teams) == -1)
        puts("No team data was found (file empty or inexistant).");
}
