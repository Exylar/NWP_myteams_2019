/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_team
*/

#include <stdlib.h>
#include "team.h"

void delete_team(struct team_s *team)
{
    struct channel_s *channel = NULL;
    struct channel_s *old_ptr = NULL;

    if (team == NULL)
        return;
    free(team->name);
    free(team->description);
    STAILQ_FOREACH(channel, &team->channels, entries) {
        free(old_ptr);
        delete_channel(channel);
        old_ptr = channel;
    }
    free(old_ptr);
}
