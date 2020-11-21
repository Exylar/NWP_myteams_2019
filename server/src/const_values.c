/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** const_values
*/

#include "server.h"

const char *CMD_OK = "200 \"%s\"\n";
const char *LOGGED_IN = "200 \"%s\",\"%s\"\n";
const char *LOGGED_OUT = "200 \"%s\",\"%s\"\n";
const char *SUB = "200 \"%s\",\"%s\"\n";
const char *UNSUB = "200 \"%s\",\"%s\"\n";
const char *BROADCAST_LOGIN = "200 BROADCAST,LOGGEDIN,\"%s\",\"%s\"\n";
const char *BROADCAST_LOGOUT = "200 BROADCAST,LOGGEDOUT,\"%s\",\"%s\"\n";
const char *BROADCAST_MP = "200 BROADCAST,MP,\"%s\",\"%s\"\n";
const char *BROADCAST_TEAM
    = "201 BROADCAST,TEAM,\"%s\",\"%s\",\"%s\"\n";
const char *BROADCAST_CHANNEL
    = "201 BROADCAST,CHANNEL,\"%s\",\"%s\",\"%s\"\n";
const char *BROADCAST_THREAD
    = "201 BROADCAST,THREAD,\"%s\",\"%s\",\"%lu\",\"%s\",\"%s\"\n";
const char *BROADCAST_COMMENT
    = "201 BROADCAST,COMMENT,\"%s\",\"%s\",\"%s\",\"%s\"\n";
const char *TEAM_CREATED = "201 \"%s\",\"%s\",\"%s\"\n";
const char *CHANNEL_CREATED = "201 \"%s\",\"%s\",\"%s\"\n";
const char *THREAD_CREATED = "201 \"%s\",\"%s\",\"%lu\",\"%s\",\"%s\"\n";
const char *COMMENT_CREATED = "201 \"%s\",\"%s\",\"%lu\",\"%s\"\n";
const char *USER_INFO = "200 \"%s\",\"%s\",\"%d\"\n";
const char *TEAM_INFO = "200 \"%s\",\"%s\",\"%s\"\n";
const char *CHANNEL_INFO = "200 \"%s\",\"%s\",\"%s\"\n";
const char *THREAD_INFO = "200 \"%s\",\"%s\",\"%lu\",\"%s\",\"%s\"\n";
const char *CONNECTED = "220 Connection established\n";
const char *BAD_SYNTAX = "400 \"%s\"\n";
const char *INVALID_USERNAME = "400 \"This username is already used\"\n";
const char *NOT_CONNECTED
    = "401 \"You must be connected to use this command\"\n";
const char *NOT_SUB
    = "401 \"You must sub to this team to create what you want in it\"\n";
const char *ALREADY_CONNECTED
    = "403 \"You must log out before logging in again\"\n";
const char *INVALID_UUID
    = "404 \"Invalid UUID for following arg\",\"%s\",\"%s\"\n";
const char *INVALID_CMD = "405 \"Invalid command\"\n";
const char *ALREADY_EXISTS = "409 \"Alreay existing ressource\"\n";
const char *INTERNAL_ERROR = "500 \"%s\"\n";

const char *SAVE_DIR_PATH = "./.saves";
const char *SAVE_TEAMS_PATH = "./.saves/teams_save.csv";
const char *SAVE_USERS_PATH = "./.saves/users_save.csv";