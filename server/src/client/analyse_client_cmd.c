/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** analyse_client_cmd
*/

#include "commands.h"
#include "libparse.h"
#include "myteams.h"
#include "server.h"
#include <strings.h>

void analyse_client_cmd(struct client_s *client)
{
    const char *end_ptr = NULL;
    size_t len = strlen(client->socket->in);
    size_t execlen = 0;
    const char *ptr = client->socket->in;
    char **args = parse_line(ptr, &end_ptr, PARSE_COMMA);

    if (args == NULL)
        return;
    do {
        exec_client_cmd(client, args);
        free_array(args);
        if (client->need_logout == true)
            return;
        ptr = end_ptr + 1;
        args = parse_line(ptr, &end_ptr, PARSE_COMMA);
    } while (args != NULL);
    execlen = ptr - client->socket->in;
    memmove(client->socket->in, ptr, len - execlen);
    memset(client->socket->in + len - execlen, 0,
        MAX_COMMAND_LENGTH - len + execlen);
}
