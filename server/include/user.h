/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user
*/

#ifndef USER_H_
#define USER_H_

#include "client.h"
#include "message.h"
#include "team.h"
#include <uuid/uuid.h>

STAILQ_HEAD(suserhead, user_s);

struct dm_s {
    uuid_t receiver_uuid;
    struct smessageshead messages;
    STAILQ_ENTRY(dm_s) entries;
};

struct user_s {
    char *name;
    uuid_t uuid;
    STAILQ_ENTRY(user_s) entries;
    struct sclientlisthead clients;
    STAILQ_HEAD(sdmhead, dm_s) dms;
};

struct user_s *new_user(struct client_s *client, char *name);
void delete_user(struct user_s *user);
struct suserhead *get_user_list_head(void);

int broadcast(
    struct client_s *client, struct suserhead *users, const char *format, ...);
int broadcast_to_subs(
    struct client_s *client, struct team_s *team, struct suserhead *users, ...);

struct dm_s *find_dm_by_uuid(struct sdmhead *dms, uuid_t to_find);
void delete_dm(struct dm_s *dm);

void remove_user(struct suserhead *head, struct user_s *user);
struct user_s *find_user_by_name(struct suserhead *head, char *name);
struct user_s *find_user_by_uuid(struct suserhead *head, uuid_t uuid);
void add_message_to_list(struct user_s *fst, struct user_s *snd, char *message);

#endif /* !USER_H_ */
