/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** help
*/

#include "commands.h"

void help_create(void)
{
    printf("\nCreate:\n");
    printf("When the context is not defined (/use):\n");
    printf("\t/create [\"team_name\"] [\"team_description\"]: "
    "create a new team\n");
    printf("When team_uuid is defined (/use \"team_uuid\"):\n");
    printf("\t/create [\"channel_name\"] [\"channel_description\"]: "
    "create a new channel\n");
    printf("When team_uuid and channel_uuid are defined (/use \"team_id\" "
    "\"channel_uuid\"):\n");
    printf("\t/create [\"thread_title\"] [\"thread_message\"]:"
    "create a new thread\n");
    printf("When team_uuid, channel_uuid and thread_uuid are defined"
    "(/use \"team_uuid\" \"channel_uuid\" \"thread_uuid\"):\n");
    printf("\t/create [\"comment_body\"]: create a new reply\n");
}

void help_list(void)
{
    printf("\nList:\n");
    printf("When the context is not defined (/use):\n");
    printf("\t/list: list all existing teams\n");
    printf("When team_uuid is defined (/use \"team_uuid\"):\n");
    printf("\t/list: list all existing channels\n");
    printf("When team_uuid and channel_uuid are defined (/use "
    "\"team_id\" \"channel_uuid\"):\n");
    printf("\t/list: list all existing threads\n");
    printf("When team_uuid, channel_uuid and thread_uuid are "
    "defined (/use \"team_uuid\" \"channel_uuid\" \"thread_uuid\"):\n");
    printf("\t/list: list all existing replies\n");
}

void help_info(void)
{
    printf("\nInfo:\n");
    printf("When the context is not defined (/use):\n");
    printf("\t/info: display currently logged user\n");
    printf("When team_uuid is defined (/use \"team_uuid±\"):\n");
    printf("\t/info: display currently selected team infos\n");
    printf("When team_uuid and channel_uuid are defined (/use \"team_id\" "
    "\"channel_uuid\"):\n");
    printf("\t/info: display currently selected channel infos\n");
    printf("When team_uuid, channel_uuid and thread_uuid are defined (/use "
    "\"team_uuid\" \"channel_uuid\" \"thread_uuid\"):\n");
    printf("\t/info: display currently selected thread infos\n");
}

void help_command_part1(void)
{
    printf("/help: show help\n");
    printf("/login [\"username\"]: set the username used by client\n");
    printf("/logout: disconnect the client from the server\n");
    printf("/users: get the list of all users that exist on the domain\n");
    printf("/user [\"user_uuid\"]: get information about a user\n");
    printf("/send [\"user_uuid\"] [\"message_body\"]: send a message to a "
    "user\n");
}

int help_command(client_t *client)
{
    (void)client;
    help_command_part1();
    printf("/messages [\"user_uuid\"]: list all messages exchange with an "
    "user\n");
    printf("/subscribe [\"team_uuid\"]: subscribe to the event of a team "
    "and its sub directories (enable reception of all events from a team)\n");
    printf("/subscribed ?[\"team_uuid\"]: list all subscribed teams or list "
    "all users subscribed to a team\n");
    printf("/unsubscribe [\"team_uuid\"]: unsubscribe from a team\n");
    printf("/use ?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"]: use "
    "specify a context team/channel/thread\n");
    printf("/create: based on what is being used create the sub resource\n");
    printf("/list: based on what is being used list all the sub resources\n");
    printf("/info: based on what is being used list the current\n");
    help_create();
    help_list();
    help_info();
    return 0;
}