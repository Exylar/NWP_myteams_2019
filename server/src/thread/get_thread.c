/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_thread
*/

#include "server.h"

struct thread_s *get_thread(struct sthreadhead *threads, uuid_t thread_uuid,
struct client_s *client)
{
    struct thread_s *thread = find_thread_by_uuid(threads, thread_uuid);
    char unparsed_thread_uuid[UUID_STR_LEN] = {'\0'};

    if (thread == NULL) {
        uuid_unparse(thread_uuid, unparsed_thread_uuid);
        cprintf(client, INVALID_UUID, "thread", unparsed_thread_uuid);
        return NULL;
    }
    return thread;
}