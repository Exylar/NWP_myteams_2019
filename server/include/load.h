/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load
*/

#ifndef LOAD_H_
#define LOAD_H_

#include "server.h"

extern const char *SAVE_TEAMS_PATH;
extern const char *SAVE_USERS_PATH;

char *get_next_line(FILE *fstream);
char *map_file(const char *filepath, off_t *size);

void load_data(struct suserhead *users, struct steamhead *teams);

struct load_fct_s {
    const char *mnemonic;
    void (*fct)(void *, char **);
    size_t arg_nb;
};

#define LOADER(name, arg_nb) \
    { #name, (void (*)(void *, char **))&load_##name, arg_nb }
#define LOADER_END { NULL, NULL, 0 }
extern const struct load_fct_s TEAM_LOADERS[];
extern const struct load_fct_s USER_LOADERS[];

void load_team(struct steamhead *head, char **args);
void load_sub(struct steamhead *head, char **args);
void load_channel(struct steamhead *head, char **args);
void load_thread(struct steamhead *head, char **args);
void load_comment(struct steamhead *head, char **args);

void load_user(struct suserhead *head, char **args);
void load_dm(struct suserhead *head, char **args);
void load_message(struct suserhead *head, char **args);

#endif /* !LOAD_H_ */
