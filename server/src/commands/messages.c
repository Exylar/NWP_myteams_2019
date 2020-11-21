/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** messages
*/

#include "server.h"

static const char *MESSAGE_INFO_LIST = "\"%s\",\"%lu\",\"%s\"";

static void send_infos(struct client_s *client, struct dm_s *dm)
{
    char unparsed_user_uuid[UUID_STR_LEN] = {'\0'};
    struct message_s *message = NULL;

    cprintf(client, "200 ");
    STAILQ_FOREACH(message, &dm->messages, entries) {
        uuid_unparse(message->sender_uuid, unparsed_user_uuid);
        cprintf(client, MESSAGE_INFO_LIST, unparsed_user_uuid,
message->timestamp, message->message);
        if (message->entries.stqe_next != NULL)
            cprintf(client, ";");
        memset(unparsed_user_uuid, '\0', UUID_STR_LEN);
    }
    cprintf(client, "\n");
}

void messages_cmd(struct client_s *client, struct suserhead *users,
struct steamhead *teams UNU, char **params)
{
    struct user_s *user = NULL;
    struct dm_s *dm = NULL;
    uuid_t user_uuid = {'\0'};

    user = find_user_by_uuid(users, client->uuid);
    if (uuid_parse(params[1], user_uuid) == -1) {
        cprintf(client, INVALID_UUID, "user", params[1]);
        return;
    }
    dm = find_dm_by_uuid(&user->dms, user_uuid);
    if (!dm) {
        cprintf(client, INVALID_UUID, "user", params[1]);
        return;
    }
    send_infos(client, dm);
}