/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** response
*/

#ifndef RESPONSE_H_
#define RESPONSE_H_

#include "cli.h"

void print_create(client_t *client);
void print_info(client_t *client);
void print_list(client_t *client);
void print_login(client_t *client);
void print_logout(client_t *client);
void print_messages(client_t *client);
void print_send(client_t *client);
void print_subscribe(client_t *client);
void print_subscribed(client_t *client);
void print_unsubscribe(client_t *client);
void print_use(client_t *client);
void print_user(client_t *client);
void print_users(client_t *client);
void broadcast(client_t *client);


#endif /* !RESPONSE_H_ */
