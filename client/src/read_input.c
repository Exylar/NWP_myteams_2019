/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** input
*/

#include "myteams.h"
#include "cli.h"
#include "consts.h"
#include "libparse.h"

void exec_command(client_t *client, int i)
{
    queue_t *element;

    if (my_commands[i].func(client) && i >= 2) {
        element = malloc(sizeof(queue_t));
        element->func = receive_commands[i - 2].func;
        STAILQ_INSERT_TAIL(&client->head, element, next);
        client->sockets->need_write = true;
    }
}

void find_command(client_t *client)
{
    for (int i = 0; my_commands[i].command != NULL; i++) {
        if (strcmp(my_commands[i].command, client->parsed_command[0]) == 0) {
            client->nb_params = get_number_paramters(client->parsed_command);
            exec_command(client, i);
            return;
        }
    }
    printf("Command unknown\n");
}

void do_parse_command(client_t *client, int len, int execlen)
{
    const char *ptr;
    const char *end_ptr;

    ptr = client->cmd_buffer;
    client->parsed_command = parse_line(ptr, &end_ptr, PARSE_SPACE);
    if (client->parsed_command == NULL)
        return;
    do {
        client->command = strdup(ptr);
        find_command(client);
        ptr = end_ptr + 1;
        free(client->command);
        free_array(client->parsed_command);
        client->parsed_command = parse_line(ptr, &end_ptr, PARSE_SPACE);
    } while (client->parsed_command != NULL);
    execlen = ptr - client->cmd_buffer;
    memmove(client->cmd_buffer, ptr, len - execlen);
    memset(client->cmd_buffer + len - execlen, 0,
    MAX_COMMAND_LENGTH - len + execlen);
}

void read_input_command(client_t *client)
{
    int size = 0;
    char buffer[MAX_COMMAND_LENGTH + 1] = {'\0'};
    size_t len = 0;
    size_t execlen = 0;

    size = read(client->sockets->fd_in, buffer, MAX_COMMAND_LENGTH);
    if (size == 0) {
        close(client->fdsocket);
        exit(0);
    }
    strcat(client->cmd_buffer, buffer);
    len = strlen(client->cmd_buffer);
    do_parse_command(client, len, execlen);
}
