/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "server.h"

void create_channel(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void create_team(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void create_thread(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void create_comment(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);

void info_user(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void info_team(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void info_channel(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void info_thread(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);

void list_team(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void list_channel(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void list_thread(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void list_comment(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);

void create_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void info_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void list_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void login_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void logout_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void send_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void user_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void users_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void noop_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void messages_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void subscribe_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void unsubscribe_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);
void subscribed_cmd(struct client_s *client, struct suserhead *users,
    struct steamhead *teams, char **params);

struct command_s {
    const char *mnemonic;
    void (*fct)(
        struct client_s *, struct suserhead *, struct steamhead *, char **);
    bool must_be_logged_in;
    size_t arg_nb;
};

#define CMD(name, log, arg_nb) { #name, name ## _cmd, log, arg_nb }
#define CREATE_CMD(name, arg_nb) { #name, create_##name, true, arg_nb }
#define INFO_CMD(name, arg_nb) { #name, info_##name, true, arg_nb }
#define LIST_CMD(name, arg_nb) { #name, list_##name, true, arg_nb }
#define CMD_END { NULL, NULL, false, 0 }

extern const struct command_s CMDS[];
extern const struct command_s CREATE_CMDS[];
extern const struct command_s INFO_CMDS[];
extern const struct command_s LIST_CMDS[];

#endif /* !COMMANDS_H_ */
