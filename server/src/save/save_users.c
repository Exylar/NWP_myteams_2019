/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save_users
*/

#include "save.h"

static void save_user(struct user_s *user, FILE *file)
{
    char unparsed_user_uuid[UUID_STR_LEN] = {'\0'};

    uuid_unparse(user->uuid, unparsed_user_uuid);
    fprintf(file, "USER,\"%s\",\"%s\"\n", unparsed_user_uuid, user->name);
    save_dms(&user->dms, file, unparsed_user_uuid);
}

int save_users(struct suserhead *users)
{
    FILE *file = open_file(SAVE_USERS_PATH);
    struct user_s *user = NULL;

    if (!file)
        return -1;
    STAILQ_FOREACH(user, users, entries) {
        save_user(user, file);
    }
    fclose(file);
    return 0;
}