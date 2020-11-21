/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "server.h"

void send_message(struct client_s *client, struct user_s *sender,
struct user_s *receiver, char *message)
{
    char uuid_sender[UUID_STR_LEN] = {'\0'};
    char uuid_reveiver[UUID_STR_LEN] = {'\0'};

    add_message_to_list(sender, receiver, message);
    uuid_unparse(sender->uuid, uuid_sender);
    uuid_unparse(receiver->uuid, uuid_reveiver);
    server_event_private_message_sended(uuid_sender, uuid_reveiver, message);
    if (receiver->clients.stqh_first != NULL)
        cprintf_loop(&receiver->clients, BROADCAST_MP, uuid_sender, message);
    cprintf(client, CMD_OK, "Message sent");
}

void send_cmd(struct client_s *client, struct suserhead *users,
struct steamhead *teams UNU, char **params)
{
    struct user_s *sender = NULL;
    struct user_s *receiver = NULL;
    uuid_t to_find = {0};

    if (uuid_parse(params[1], to_find) == -1) {
        cprintf(client, INVALID_UUID, "user", params[1]);
        return;
    }
    receiver = find_user_by_uuid(users, to_find);
    if (!receiver) {
        cprintf(client, INVALID_UUID, "user", params[1]);
        return;
    }
    sender = find_user_by_uuid(users, client->uuid);
    if (uuid_compare(sender->uuid, receiver->uuid) == 0) {
        cprintf(client, INVALID_UUID, "user", params[1]);
        return;
    }
    send_message(client, sender, receiver, params[2]);
}