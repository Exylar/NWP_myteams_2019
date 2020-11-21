/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** add_message_to_list
*/

#include "server.h"

static struct message_s *create_message(char *message, uuid_t sender_uuid,
time_t timestamp)
{
    struct message_s *new_message = calloc(1, sizeof(struct message_s));

    new_message->message = strdup(message);
    uuid_copy(new_message->sender_uuid, sender_uuid);
    new_message->timestamp = timestamp;
    return new_message;
}

static struct dm_s *create_dm(struct user_s *user)
{
    struct dm_s *new_dm = calloc(1, sizeof(struct dm_s));

    uuid_copy(new_dm->receiver_uuid, user->uuid);
    STAILQ_INIT(&new_dm->messages);
    return new_dm;
}

void add_message_to_list(struct user_s *fst_user,
struct user_s *snd_user, char *message)
{
    struct dm_s *fst_dm = find_dm_by_uuid(&fst_user->dms, snd_user->uuid);
    struct dm_s *snd_dm = find_dm_by_uuid(&snd_user->dms, fst_user->uuid);
    struct message_s *fst_msg = NULL;
    struct message_s *snd_msg = NULL;
    time_t timestamp = time(NULL);

    if (fst_dm == NULL) {
        fst_dm = create_dm(snd_user);
        snd_dm = create_dm(fst_user);
        STAILQ_INSERT_TAIL(&fst_user->dms, fst_dm, entries);
        STAILQ_INSERT_TAIL(&snd_user->dms, snd_dm, entries);
    }
    fst_msg = create_message(message, fst_user->uuid, timestamp);
    snd_msg = create_message(message, fst_user->uuid, timestamp);
    STAILQ_INSERT_TAIL(&fst_dm->messages, fst_msg, entries);
    STAILQ_INSERT_TAIL(&snd_dm->messages, snd_msg, entries);
}