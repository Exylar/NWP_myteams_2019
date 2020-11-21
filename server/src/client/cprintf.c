/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cprintf
*/

#include "user.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void cprintf(struct client_s *client, const char *format, ...)
{
    char buf[MAX_COMMAND_LENGTH + 1] = {};
    va_list ap;
    size_t len = strlen(client->socket->out);

    va_start(ap, format);
    vsnprintf(buf, MAX_COMMAND_LENGTH + 1, format, ap);
    va_end(ap);
    strncat(client->socket->out, buf, MAX_COMMAND_LENGTH - len);
    client->socket->need_write = true;
}

void cprintf_loop(struct sclientlisthead *clients, const char *format, ...)
{
    va_list ap;
    struct client_list_s *elem = NULL;

    va_start(ap, format);
    STAILQ_FOREACH(elem, clients, entries) {
        vcprintf(elem->client, format, ap);
    }
    va_end(ap);
}