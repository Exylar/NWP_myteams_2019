/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** broadcast
*/

#include <stdarg.h>
#include "server.h"

int broadcast_to_subs(struct client_s *client, struct team_s *team,
struct suserhead *users, ...)
{
    char *format = NULL;
    struct user_s *user = NULL;
    va_list ap;

    va_start(ap, users);
    format = va_arg(ap, char *);
    STAILQ_FOREACH(user, users, entries) {
        if (uuid_compare(user->uuid, client->uuid) == 0)
            continue;
        if (find_sub_by_uuid(&team->uuids, user->uuid) != NULL
&& user->clients.stqh_first != NULL)
            vcprintf_loop(&user->clients, format, ap);
    }
    va_end(ap);
    return 0;
}

int broadcast(struct client_s *client, struct suserhead *users,
const char *format, ...)
{
    struct user_s *user = NULL;
    va_list ap;

    va_start(ap, format);
    STAILQ_FOREACH(user, users, entries) {
        if (uuid_compare(client->uuid, user->uuid) == 0)
            continue;
        if (user->clients.stqh_first != NULL)
            vcprintf_loop(&user->clients, format, ap);
    }
    va_end(ap);
    return 0;
}
