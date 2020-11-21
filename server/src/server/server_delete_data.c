/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_delete_data
*/

#include "server.h"

void server_delete_data(void)
{
    struct suserhead *users = get_user_list_head();
    struct steamhead *teams = get_team_list_head();
    struct user_s *user = NULL;
    struct team_s *team = NULL;
    void *old_ptr = NULL;

    STAILQ_FOREACH(user, users, entries) {
        free(old_ptr);
        delete_user(user);
        old_ptr = user;
    }
    STAILQ_FOREACH(team, teams, entries) {
        free(old_ptr);
        delete_team(team);
        old_ptr = team;
    }
    free(old_ptr);
}
