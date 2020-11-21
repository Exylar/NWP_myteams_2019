/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_message
*/

#include "load.h"

static struct dm_s *find_dm(struct suserhead *head, char *user_uuid,
    char *receiver_uuid)
{
    struct user_s *user;
    uuid_t uuidbuf = {};

    if (uuid_parse(user_uuid, uuidbuf) == -1)
        return NULL;
    user = find_user_by_uuid(head, uuidbuf);
    if (user == NULL)
        return NULL;
    if (uuid_parse(receiver_uuid, uuidbuf) == -1)
        return NULL;
    return find_dm_by_uuid(&user->dms, uuidbuf);
}

void load_message(struct suserhead *head, char **args)
{
    struct message_s *message = calloc(1, sizeof(struct message_s));
    struct dm_s *dm = find_dm(head, args[1], args[2]);
    char *ptr;

    if (dm == NULL)
        return free(message);
    if (uuid_parse(args[3], message->sender_uuid) == -1)
        return free(message);
    message->message = strdup(args[4]);
    message->timestamp = strtol(args[5], &ptr, 10);
    if (*ptr != '\0')
        return free(message);
    STAILQ_INSERT_TAIL(&dm->messages, message, entries);
}
