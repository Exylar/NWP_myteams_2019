/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** redirect_signals
*/

#include "server.h"
#include <signal.h>

static void sig_handler(UNU int signo)
{
    puts("Caught signal, shutting down...");
    server_need_shutdown(SET(true));
}

int redirect_signals(void)
{
    struct sigaction act = {};

    act.sa_handler = &sig_handler;
    if (sigaction(SIGINT, &act, NULL) == -1)
        return -1;
    if (sigaction(SIGTERM, &act, NULL) == -1)
        return -1;
    return 0;
}
