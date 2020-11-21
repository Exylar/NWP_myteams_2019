/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message
*/

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <sys/queue.h>
#include <time.h>
#include <uuid/uuid.h>

STAILQ_HEAD(smessageshead, message_s);

struct message_s
{
    uuid_t sender_uuid;
    char *message;
    time_t timestamp;
    STAILQ_ENTRY(message_s) entries;
};

struct message_s *get_new_comment(char *message, uuid_t sender_uuid);
void delete_comment(struct message_s *comment);

#endif /* !MESSAGE_H_ */
