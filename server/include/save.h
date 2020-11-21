/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save
*/

#ifndef SAVE_H_
#define SAVE_H_

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

extern const char *SAVE_DIR_PATH;
extern const char *SAVE_TEAMS_PATH;
extern const char *SAVE_USERS_PATH;

FILE *open_file(const char *path);
int check_directory(void);

int save_users(struct suserhead *users);
void save_dms(struct sdmhead *dms, FILE *file, char *unparsed_user_uuid);
int save_teams(struct steamhead *teams);
void save_channels(struct schannelhead *channels, FILE *file,
char *unparsed_team_uuid);
void save_threads(struct sthreadhead *threads, FILE *file,
char *unparsed_team_uuid, char *unparsed_channel_uuid);
void save_messages(struct smessageshead *messages, FILE *file,
char *unparsed_uuids, char *mnemonic);
int save_data(struct suserhead *users, struct steamhead *teams);

#endif /* !SAVE_H_ */
