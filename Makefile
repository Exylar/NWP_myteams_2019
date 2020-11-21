##
## EPITECH PROJECT, 2020
## Fairefichier
## File description:
## This is a fairefichier, made by HeyShafty
##

COLOR_THEME	=	$(BLUE_C)
MAKE_RULE	=	all

all: message libs client server

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"MY TEAMS"$(DEFAULT)

libs:
	@make -C libs -s $(MAKE_RULE)

client:
	@make -C client -s $(MAKE_RULE)

server:
	@make -C server -s $(MAKE_RULE)

clean:
	@make clean -C libs -s
	@make clean -C client -s
	@make clean -C server -s

fclean:	clean
	@make fclean -C libs -s
	@make fclean -C client -s
	@make fclean -C server -s

re: fclean all

tests_run: MAKE_RULE = tests_run
tests_run: all

debug: MAKE_RULE = debug
debug: all

.PHONY: all message clean fclean re debug tests_run client server libs

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
