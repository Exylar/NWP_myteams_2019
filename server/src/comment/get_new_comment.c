/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_new_comment
*/

#include "server.h"

struct message_s *get_new_comment(char *message, uuid_t sender_uuid)
{
    struct message_s *new_comment = malloc(sizeof(struct message_s));

    new_comment->message = strdup(message);
    uuid_copy(new_comment->sender_uuid, sender_uuid);
    new_comment->timestamp = time(NULL);
    return new_comment;
}