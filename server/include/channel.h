/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel
*/

#include "thread.h"

STAILQ_HEAD(schannelhead, channel_s);

struct channel_s
{
    uuid_t uuid;
    char *name;
    char *description;
    STAILQ_ENTRY(channel_s) entries;
    struct sthreadhead threads;
};

struct channel_s *get_new_channel(char *name, char *description);
void delete_channel(struct channel_s *channel);

struct channel_s *find_channel_by_name(struct schannelhead *channels,
char *name);
struct channel_s *find_channel_by_uuid(struct schannelhead *channels,
uuid_t uuid);