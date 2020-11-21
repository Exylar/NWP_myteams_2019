/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team
*/

#ifndef TEAM_H_
#define TEAM_H_

#include <uuid/uuid.h>
#include "channel.h"

struct uuid_list_s
{
    uuid_t uuid;
    STAILQ_ENTRY(uuid_list_s) entries;
};

struct team_s
{
    uuid_t uuid;
    char *name;
    char *description;
    STAILQ_HEAD(suuidhead, uuid_list_s) uuids;
    STAILQ_ENTRY(team_s) entries;
    struct schannelhead channels;
};

STAILQ_HEAD(steamhead, team_s);

struct steamhead *get_team_list_head(void);

struct team_s *get_new_team(char *name, char *description);
void delete_team(struct team_s *team);

struct team_s *find_team_by_uuid(struct steamhead *teams, uuid_t to_find);
struct team_s *find_team_by_name(struct steamhead *teams, char *name);

struct uuid_list_s *find_sub_by_uuid(struct suuidhead *uuids, uuid_t to_find);

#endif /* !TEAM_H_ */
