/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_comment
*/

#include <stdlib.h>
#include "message.h"

void delete_comment(struct message_s *comment)
{
    if (comment == NULL)
        return;
    free(comment->message);
}