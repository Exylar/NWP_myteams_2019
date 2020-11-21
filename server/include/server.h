/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include "logging_server.h"
#include "team.h"
#include "user.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define UNU __attribute__((unused))

struct server_s {
    struct socket_s *socket; ///< Server socket
    fd_set rset; ///< Client socket read fd set
    fd_set wset; ///< Client socket write fd set
};

int server_loop(struct server_s *server);
struct server_s *new_server(uint16_t port);
void delete_server(struct server_s *server);
int server_wait_for_action(
    struct server_s *server, struct sclienthead *clients);
int server_add_new_client(struct server_s *server, struct sclienthead *clients);
void server_checkup_clients(
    struct server_s *server, struct sclienthead *clients);
void server_delete_data(void);

#define GET false, false
#define SET(v) true, v
bool server_need_shutdown(bool flag, bool value);

// 200
extern const char *CMD_OK;
extern const char *LOGGED_IN;
extern const char *LOGGED_OUT;
extern const char *SUB;
extern const char *UNSUB;
extern const char *BROADCAST_LOGIN;
extern const char *BROADCAST_LOGOUT;
extern const char *BROADCAST_MP;
extern const char *BROADCAST_TEAM;
extern const char *BROADCAST_CHANNEL;
extern const char *BROADCAST_THREAD;
extern const char *BROADCAST_COMMENT;
extern const char *TEAM_CREATED;
extern const char *CHANNEL_CREATED;
extern const char *THREAD_CREATED;
extern const char *COMMENT_CREATED;
extern const char *USER_INFO;
extern const char *TEAM_INFO;
extern const char *CHANNEL_INFO;
extern const char *THREAD_INFO;
extern const char *CONNECTED;

// 400
extern const char *BAD_SYNTAX;
extern const char *INVALID_USERNAME;
extern const char *NOT_CONNECTED;
extern const char *NOT_SUB;
extern const char *ALREADY_CONNECTED;
extern const char *INVALID_UUID;
extern const char *INVALID_CMD;
extern const char *ALREADY_EXISTS;

// 500
extern const char *INTERNAL_ERROR;

size_t my_array_len(void *array);
int redirect_signals(void);
void free_array(char **array);
bool check_args_number(char **params, int fd, size_t nb);
struct team_s *get_team(
    struct steamhead *teams, uuid_t team_uuid, struct client_s *client);
struct channel_s *get_channel(struct schannelhead *channels,
    uuid_t channel_uuid, struct client_s *client);
struct thread_s *get_thread(
    struct sthreadhead *threads, uuid_t thread_uuid, struct client_s *client);

#endif /* !SERVER_H_ */
