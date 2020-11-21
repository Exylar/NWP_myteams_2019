/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** cli
*/

#ifndef __MY_FPT_H__
#define __MY_FPT_H__

#include "myteams.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>
#include <sys/select.h>
#include <unistd.h>
#define MAX_QUEUE 10

typedef struct sockets_s {
    int fd_in;
    char buffer[MAX_COMMAND_LENGTH + 1];
    bool need_write;
} sockets_t;

typedef struct context_s {
    char *uuid_team;
    char *uuid_channel;
    char *uuid_thread;
} context_t;

typedef struct client_s {
    int fdsocket;
    char *ip;
    int port;
    char *uuid;
    char *username;
    char *cmd_buffer;
    char *command;
    int nb_params;
    char **parsed_command;
    char *receive_command;
    STAILQ_HEAD(, queue_s) head;
    sockets_t *sockets;
    int is_logged;
    context_t *context;
} client_t;

typedef struct queue_s {
    void (*func)(client_t *client);
    STAILQ_ENTRY(queue_s) next;
} queue_t;

int connection_to_socket(char *ip, int port);

client_t *init_client_struct(char *ip, int port, int fdsocket);
void init_fd_struct(client_t *client);
int is_logged(client_t *client);
void free_client(client_t *client);

void client(char *ip, int port, int fdsocket);
bool client_need_shutdown(bool flag, bool value);

void find_command(client_t *client);
void command_send(client_t *client, char *buffer);
void read_input_command(client_t *client);
void find_receive_command(client_t *client, char *buffer);
void read_receive_command(client_t *client);

int redirect_signals(void);

void free_array(char **array);
int get_number_paramters(char **array);

#endif
