/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_loop
*/

#include "load.h"
#include "myteams.h"
#include "save.h"
#include <stdint.h>
#include <sys/select.h>

static void delete_clients(struct sclienthead *clients)
{
    struct client_s *prev = NULL;
    struct client_s *curr;

    STAILQ_FOREACH(curr, clients, entries) {
        delete_client(prev);
        prev = curr;
    }
    delete_client(prev);
}

int server_loop(struct server_s *server)
{
    struct sclienthead clients = {};
    int ret = 0;

    STAILQ_INIT(&clients);
    if (redirect_signals() == -1)
        return -1;
    load_data(get_user_list_head(), get_team_list_head());
    while (server_need_shutdown(GET) == false) {
        server_checkup_clients(server, &clients);
        if (server_wait_for_action(server, &clients) == -1) {
            ret = -1;
            break;
        }
    }
    if (save_data(get_user_list_head(), get_team_list_head()) == -1)
        ret = -1;
    delete_clients(&clients);
    server_delete_data();
    return ret;
}
