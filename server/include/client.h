/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include "myteams.h"
#include "socket.h"
#include <sys/queue.h>
#include <uuid/uuid.h>

STAILQ_HEAD(sclienthead, client_s);
STAILQ_HEAD(sclientlisthead, client_list_s);

struct client_s {
    uuid_t uuid;
    struct socket_s *socket;
    bool logged_in;
    bool need_logout;
    STAILQ_ENTRY(client_s) entries;
};

struct client_list_s {
    struct client_s *client;
    STAILQ_ENTRY(client_list_s) entries;
};

struct client_s *new_client(void);
void delete_client(struct client_s *client);

struct client_list_s *new_client_list(struct client_s *client);
void delete_client_list(struct client_list_s *list);
struct client_list_s *find_client_list_by_client(
    struct sclientlisthead *head, struct client_s *client);

int read_from_client(struct client_s *client);
void write_to_client(struct client_s *client);
void analyse_client_cmd(struct client_s *client);
void exec_client_cmd(struct client_s *client, char **args);

void cprintf(struct client_s *client, const char *format, ...);
void cprintf_loop(struct sclientlisthead *clients, const char *format, ...);
void vcprintf(struct client_s *client, const char *format, va_list ap);
void vcprintf_loop(struct sclientlisthead *clients,
const char *format, va_list ap);

#endif /* !CLIENT_H_ */
