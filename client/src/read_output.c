/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** output
*/

#include "myteams.h"
#include "cli.h"
#include "consts.h"
#include "response.h"

void find_receive_command(client_t *client, char *buffer)
{
    queue_t *queue;

    client->receive_command = buffer;
    if (strstr(client->receive_command, "220"))
        return;
    if (strstr(client->receive_command, "BROADCAST")) {
        broadcast(client);
        return;
    }
    if (!STAILQ_EMPTY(&client->head)) {
        queue = STAILQ_FIRST(&client->head);
        queue->func(client);
        STAILQ_REMOVE_HEAD(&client->head, next);
        free(queue);
        return;
    }
    printf("Command unknown\n");
}

void read_receive_command(client_t *client)
{
    int size = 0;
    char buffer[MAX_COMMAND_LENGTH + 1] = {'\0'};

    size = read(client->fdsocket, buffer, MAX_COMMAND_LENGTH);
    if (size == 0) {
        client->sockets->need_write = false;
        return;
    }
    printf("%s", buffer);
    find_receive_command(client, buffer);
    memset(buffer, 0, MAX_COMMAND_LENGTH + 1);
}