#pragma once

char **command_parser_with_strtok(char *command, const char *const delims);

// lets keep it the POSIX way
char **command_parser_with_strtok_r(char *command, const char *const delims);

char *the_good_way_of_iterating_over_strings(const char *const string);

char *get_file_name_with_strchr(const char *path);

long try_parse_long(const char *const number);
