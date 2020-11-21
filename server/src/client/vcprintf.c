/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** vcprintf
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "user.h"

void vcprintf(struct client_s *client, const char *format, va_list ap)
{
    char buf[MAX_COMMAND_LENGTH + 1] = {'\0'};
    size_t len = strlen(client->socket->out);
    va_list ap_cpy;

    va_copy(ap_cpy, ap);
    vsnprintf(buf, MAX_COMMAND_LENGTH + 1, format, ap_cpy);
    strncat(client->socket->out, buf, MAX_COMMAND_LENGTH - len);
    client->socket->need_write = true;
}

void vcprintf_loop(struct sclientlisthead *clients,
const char *format, va_list ap)
{
    struct client_list_s *elem = NULL;

    STAILQ_FOREACH(elem, clients, entries) {
        vcprintf(elem->client, format, ap);
    }
}
