/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** remove_user
*/

#include "user.h"

void remove_user(struct suserhead *head, struct user_s *user)
{
    STAILQ_REMOVE(head, user, user_s, entries);
    delete_user(user);
}
