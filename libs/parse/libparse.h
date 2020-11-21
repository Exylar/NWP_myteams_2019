/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** libparse
*/

#ifndef LIBPARSE_H_
#define LIBPARSE_H_

struct parse_sep_s {
    char c;
    const char *skip;
    const char *quote;
};

#define PARSE_COMMA (struct parse_sep_s){ ',', ",\n", "\"," }
#define PARSE_SPACE (struct parse_sep_s){ ' ', " \n", "\" " }

char **parse_args(
    const char *cmd, const char **end_ptr, struct parse_sep_s sep);
char **parse_line(
    const char *line, const char **end_ptr, struct parse_sep_s sep);

#endif /* !LIBPARSE_H_ */
