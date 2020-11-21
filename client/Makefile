##
## EPITECH PROJECT, 2020
## Fairefichier
## File description:
## This is a fairefichier, made by HeyShafty
##

NAME	=	myteams_cli
ROOT_PATH	=	./
SRC_NAME	=	src
TESTS_NAME	=	tests
INCL_NAME	=	include
CMD_NAME	=	commands
CONSTS_NAME	=	consts
RES_NAME	=	responses
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)
CMD_PATH	=	$(CMD_NAME)
RES_PATH	=	$(RES_NAME)
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
CONSTS_PATH	=	$(ROOT_PATH)$(CONSTS_NAME)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)
COLOR_THEME	=	$(BLUE_C)
DEBUG_THEME	=	$(CYAN_C)
TESTS_THEME	=	$(RED_C)

SRC	=	\
		$(CMD_PATH)/create.c \
		$(CMD_PATH)/help.c \
		$(CMD_PATH)/info.c \
		$(CMD_PATH)/list.c \
		$(CMD_PATH)/login.c \
		$(CMD_PATH)/logout.c \
		$(CMD_PATH)/messages.c \
		$(CMD_PATH)/send.c \
		$(CMD_PATH)/subscribe.c \
		$(CMD_PATH)/subscribed.c \
		$(CMD_PATH)/unsubscribe.c \
		$(CMD_PATH)/use.c \
		$(CMD_PATH)/user.c \
		$(CMD_PATH)/users.c \
		$(CONSTS_PATH)/const_error.c \
		$(CONSTS_PATH)/const_list_command.c \
		$(CONSTS_PATH)/const_values.c \
		$(RES_PATH)/broadcast.c \
		$(RES_PATH)/create.c \
		$(RES_PATH)/info.c \
		$(RES_PATH)/list.c \
		$(RES_PATH)/login.c \
		$(RES_PATH)/logout.c \
		$(RES_PATH)/messages.c \
		$(RES_PATH)/send.c \
		$(RES_PATH)/subscribe.c \
		$(RES_PATH)/subscribed.c \
		$(RES_PATH)/unsubscribe.c \
		$(RES_PATH)/user.c \
		$(RES_PATH)/users.c \
		client_need_shutdown.c \
		client_utils.c \
		client.c \
		command_utils.c \
		connection_to_socket.c \
		error.c \
		read_input.c \
		read_output.c \
		redirect_signals.c

SRCS	=	$(SRC:%=$(SRC_PATH)/%) $(SRC_PATH)/main.c
OBJ	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I ../include -I $(INCL_PATH) -I ../libs/myteams/ -I ../libs/parse
LDFLAGS	=	-L ../libs/ -L ../libs/myteams/
LDLIBS	=	-lmyteams -luuid -lparse
DEBUG_FLAGS	=	-g3 -gdwarf-4

all: message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"MY TEAMS CLI"$(DEFAULT)

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
