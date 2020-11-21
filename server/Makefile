##
## EPITECH PROJECT, 2020
## Fairefichier
## File description:
## This is a fairefichier, made by HeyShafty
##

NAME	=	myteams_server
ROOT_PATH	=	./
SRC_NAME	=	src
TESTS_NAME	=	tests
INCL_NAME	=	include
COMMANDS	=	commands
CHANNEL	=	channel
CLIENT	=	client
TEAM	=	team
THREAD	=	thread
SERVER	=	server
SOCKET	=	socket
USER	=	user
COMMENT	=	comment
DM	=	dm
SAVE	=	save
LOAD	=	load
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)
COLOR_THEME	=	$(BLUE_C)
DEBUG_THEME	=	$(CYAN_C)
TESTS_THEME	=	$(RED_C)

SRC	=	\
		$(CHANNEL)/delete_channel.c \
		$(CHANNEL)/find_channel_by_name.c \
		$(CHANNEL)/find_channel_by_uuid.c \
		$(CHANNEL)/get_channel.c \
		$(CHANNEL)/get_new_channel.c \
		$(CLIENT)/analyse_client_cmd.c \
		$(CLIENT)/check_args_number.c \
		$(CLIENT)/cprintf.c \
		$(CLIENT)/delete_client_list.c \
		$(CLIENT)/delete_client.c \
		$(CLIENT)/exec_client_cmd.c \
		$(CLIENT)/find_client_list_by_client.c \
		$(CLIENT)/new_client_list.c \
		$(CLIENT)/new_client.c \
		$(CLIENT)/read_from_client.c \
		$(CLIENT)/vcprintf.c \
		$(CLIENT)/write_to_client.c \
		$(COMMANDS)/command_list.c \
		$(COMMANDS)/create_channel.c \
		$(COMMANDS)/create_comment.c \
		$(COMMANDS)/create_team.c \
		$(COMMANDS)/create_thread.c \
		$(COMMANDS)/create.c \
		$(COMMANDS)/info_channel.c \
		$(COMMANDS)/info_team.c \
		$(COMMANDS)/info_thread.c \
		$(COMMANDS)/info_user.c \
		$(COMMANDS)/info.c \
		$(COMMANDS)/list_channel.c \
		$(COMMANDS)/list_comment.c \
		$(COMMANDS)/list_team.c \
		$(COMMANDS)/list_thread.c \
		$(COMMANDS)/list.c \
		$(COMMANDS)/login.c \
		$(COMMANDS)/logout.c \
		$(COMMANDS)/messages.c \
		$(COMMANDS)/noop.c \
		$(COMMANDS)/send.c \
		$(COMMANDS)/subscribe.c \
		$(COMMANDS)/subscribed.c \
		$(COMMANDS)/unsubscribe.c \
		$(COMMANDS)/user.c \
		$(COMMANDS)/users.c \
		$(COMMENT)/delete_comment.c \
		$(COMMENT)/get_new_comment.c \
		$(DM)/delete_dm.c \
		$(DM)/find_dm_by_uuid.c \
		$(LOAD)/get_next_line.c \
		$(LOAD)/load_channel.c \
		$(LOAD)/load_comment.c \
		$(LOAD)/load_data.c \
		$(LOAD)/load_dm.c \
		$(LOAD)/load_message.c \
		$(LOAD)/load_sub.c \
		$(LOAD)/load_team.c \
		$(LOAD)/load_thread.c \
		$(LOAD)/load_user.c \
		$(LOAD)/loaders.c \
		$(LOAD)/map_file.c \
		$(SAVE)/check_directory.c \
		$(SAVE)/open_file.c \
		$(SAVE)/save_channels.c \
		$(SAVE)/save_data.c \
		$(SAVE)/save_dms.c \
		$(SAVE)/save_messages.c \
		$(SAVE)/save_teams.c \
		$(SAVE)/save_threads.c \
		$(SAVE)/save_users.c \
		$(SERVER)/delete_server.c \
		$(SERVER)/new_server.c \
		$(SERVER)/server_add_new_client.c \
		$(SERVER)/server_checkup_clients.c \
		$(SERVER)/server_delete_data.c \
		$(SERVER)/server_loop.c \
		$(SERVER)/server_need_shutdown.c \
		$(SERVER)/server_wait_for_action.c \
		$(SOCKET)/accept_connection.c \
		$(SOCKET)/delete_socket.c \
		$(SOCKET)/new_socket.c \
		$(TEAM)/delete_team.c \
		$(TEAM)/find_sub_by_uuid.c \
		$(TEAM)/find_team_by_name.c \
		$(TEAM)/find_team_by_uuid.c \
		$(TEAM)/get_new_team.c \
		$(TEAM)/get_team_list_head.c \
		$(TEAM)/get_team.c \
		$(THREAD)/delete_thread.c \
		$(THREAD)/find_thread_by_name.c \
		$(THREAD)/find_thread_by_uuid.c \
		$(THREAD)/get_new_thread.c \
		$(THREAD)/get_thread.c \
		$(USER)/add_message_to_list.c \
		$(USER)/broadcast.c \
		$(USER)/delete_user.c \
		$(USER)/find_user_by_name.c \
		$(USER)/find_user_by_uuid.c \
		$(USER)/get_user_list_head.c \
		$(USER)/new_user.c \
		$(USER)/remove_user.c \
		const_values.c \
		free_array.c \
		my_array_len.c \
		redirect_signals.c

SRCS	=	$(SRC:%=$(SRC_PATH)/%) $(SRC_PATH)/main.c
OBJ	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -Wno-unknown-pragmas -I ../include/ -I include/ -I ../libs/myteams/ -I ../libs/parse
LDFLAGS	=	-L ../libs/ -L ../libs/myteams/
LDLIBS	=	-lmyteams -luuid -lparse
DEBUG_FLAGS	=	-g3 -gdwarf-4

all: message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"MY TEAMS SERVER"$(DEFAULT)

$(NAME): libparse $(OBJ)
	@$(CC) -o ../$(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

libparse:
	@make -C ../libs/parse -s

clean:
	@make fclean -C $(TESTS_PATH) -s SRC="$(SRC)" COLOR_THEME="$(RED_C)"
	@$(RM) $(OBJ) && \
		$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) $(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) $(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) vgcore.* && \
		$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) $(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) $(LIGHT_RED)"Valgrind files"$(DEFAULT)

fclean:	clean
	@$(RM) results.html && \
		$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) $(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) $(LIGHT_RED)"results.html"$(DEFAULT)
	@$(RM) ../$(NAME) && \
		$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) $(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) $(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)

re: fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: COLOR_THEME = $(DEBUG_THEME)
debug: re
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"⚠ DEBUG MODE ACTIVATED ⚠\n"$(DEFAULT)

tests_run:
	@make -C $(TESTS_PATH) re -s \
		SRC="$(SRC)" \
		COLOR_THEME="$(TESTS_THEME)"
	@$(ECHO) $(TESTS_THEME)""
	@gcovr --exclude tests/ --sort-percentage --branches
	@$(ECHO) $(BOLD_T)""
	@gcovr --exclude tests/ --sort-percentage --print-summary
	@$(ECHO) $(DEFAULT)
	@gcovr --exclude tests/ --sort-percentage --html-details --html-title "Unit tests" --html-medium-threshold 40 --html-high-threshold 75 > results.html

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all message clean fclean re debug tests_run

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""
