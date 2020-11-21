/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread
*/

#ifndef THREAD_H_
#define THREAD_H_

#include "message.h"

STAILQ_HEAD(sthreadhead, thread_s);

struct thread_s
{
    uuid_t uuid;
    uuid_t user_uuid;
    char *title;
    char *body;
    time_t timestamp;
    struct smessageshead comments;
    STAILQ_ENTRY(thread_s) entries;
};

struct thread_s *get_new_thread(char *name, char *body, uuid_t user_uuid);
void delete_thread(struct thread_s *thread);

struct thread_s *find_thread_by_uuid(struct sthreadhead *threads,
uuid_t to_find);
struct thread_s *find_thread_by_name(struct sthreadhead *threads, char *name);

#endif /* !THREAD_H_ */
