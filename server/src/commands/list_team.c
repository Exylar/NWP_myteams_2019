/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_team
*/

#include "server.h"

static const char *TEAM_INFO_LIST = "\"%s\",\"%s\",\"%s\"";

void list_team(struct client_s *client, struct suserhead *users UNU,
struct steamhead *teams, char **params UNU)
{
    char unparsed_team_uuid[UUID_STR_LEN] = {'\0'};
    struct team_s *team = NULL;

    cprintf(client, "200 ");
    STAILQ_FOREACH(team, teams, entries) {
        uuid_unparse(team->uuid, unparsed_team_uuid);
        cprintf(client, TEAM_INFO_LIST, unparsed_team_uuid, team->name,
team->description);
        if (team->entries.stqe_next != NULL)
            cprintf(client, ";");
        memset(unparsed_team_uuid, '\0', UUID_STR_LEN);
    }
    cprintf(client, "\n");
}