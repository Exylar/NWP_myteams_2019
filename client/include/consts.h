/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** consts
*/

#ifndef CONSTS_H_
#define CONSTS_H_

#define NB_COMMANDS 15
#define NB_RECEIVE_COMMANDS 14

#include "cli.h"

typedef struct command_s {
    char *command;
    int (*func)(client_t *client);
} command_t;

typedef struct command_receive_s {
    char *command;
    void (*func)(client_t *client);
} command_receive_t;

const command_t my_commands[NB_COMMANDS];
const command_receive_t receive_commands[NB_RECEIVE_COMMANDS];

extern const char LIST[];
extern const char LOGIN[];
extern const char LOGOUT[];
extern const char MESSAGE[];
extern const char SEND[];
extern const char SUBSCRIBE[];
extern const char SUBSCRIBED[];
extern const char UNSUBSCRIBE[];
extern const char USE[];
extern const char USER[];
extern const char USERS[];

extern const char CREATE_TEAM[];
extern const char CREATE_CHANNEL[];
extern const char CREATE_THREAD[];
extern const char CREATE_MESSAGE[];

extern const char LIST_TEAM[];
extern const char LIST_CHANNEL[];
extern const char LIST_THREAD[];
extern const char LIST_MESSAGE[];

extern const char INFO_USER[];
extern const char INFO_TEAM[];
extern const char INFO_CHANNEL[];
extern const char INFO_THREAD[];

#endif /* !CONSTS_H_ */
