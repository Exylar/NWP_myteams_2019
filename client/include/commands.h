/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "cli.h"

int create(client_t *client);
int help_command(client_t *client);
int info(client_t *client);
int list(client_t *client);
int login(client_t *client);
int logout(client_t *client);
int messages(client_t *client);
int send_cmd(client_t *client);
int subscribe(client_t *client);
int subscribed(client_t *client);
int unsubscribe(client_t *client);
int use(client_t *client);
int user(client_t *client);
int users(client_t *client);

#endif /* !COMMANDS_H_ */
