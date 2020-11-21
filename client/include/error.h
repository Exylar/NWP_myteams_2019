/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** error
*/

#ifndef ERROR_H_
#define ERROR_H_

#define NB_ERROR_COMMAND 5

#include "cli.h"

enum type_error {
    USER_ERROR,
    TEAM_ERROR,
    CHANNEL_ERROR,
    THREAD_ERROR,
};

typedef struct error_s {
    int (*func)(const char *);
} error_t;

extern const error_t unknown_error[NB_ERROR_COMMAND];

int error_message_parms(char *type, int value);
int error_commands(char *message);
void print_unknown_error(client_t *client, enum type_error type);
void error_uuid_context(client_t *client);

#endif /* !ERROR_H_ */
