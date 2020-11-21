/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team
*/

#include "save.h"

static void save_message(struct message_s *message, FILE *file,
char *unparsed_uuids, char *mnemonic)
{
    char unparsed_sender_uuid[UUID_STR_LEN] = {'\0'};

    uuid_unparse(message->sender_uuid, unparsed_sender_uuid);
    fprintf(file, "%s,%s,\"%s\",\"%s\",\"%lu\"\n", mnemonic, unparsed_uuids,
unparsed_sender_uuid, message->message, message->timestamp);
}

void save_messages(struct smessageshead *messages, FILE *file,
char *unparsed_uuids, char *mnemonic)
{
    struct message_s *message = NULL;

    STAILQ_FOREACH(message, messages, entries) {
        save_message(message, file, unparsed_uuids, mnemonic);
    }
}
