/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save_team
*/

#include "save.h"

static void save_subs(struct suuidhead *subs, FILE *file,
char *unparsed_team_uuid)
{
    struct uuid_list_s *uuid = NULL;
    char unparsed_sub_uuid[UUID_STR_LEN] = {'\0'};

    STAILQ_FOREACH(uuid, subs, entries) {
        uuid_unparse(uuid->uuid, unparsed_sub_uuid);
        fprintf(file, "SUB,\"%s\",\"%s\"\n", unparsed_team_uuid,
unparsed_sub_uuid);
        memset(unparsed_sub_uuid, '\0', UUID_STR_LEN);
    }
}

static void save_team(struct team_s *team, FILE *file)
{
    char unparsed_team_uuid[UUID_STR_LEN] = {'\0'};

    uuid_unparse(team->uuid, unparsed_team_uuid);
    fprintf(file, "TEAM,\"%s\",\"%s\",\"%s\"\n", unparsed_team_uuid,
team->name, team->description);
    save_subs(&team->uuids, file, unparsed_team_uuid);
    save_channels(&team->channels, file, unparsed_team_uuid);
}

int save_teams(struct steamhead *teams)
{
    struct team_s *team = NULL;
    FILE *file = open_file(SAVE_TEAMS_PATH);

    if (!file)
        return -1;
    STAILQ_FOREACH(team, teams, entries) {
        save_team(team, file);
    }
    fclose(file);
    return 0;
}