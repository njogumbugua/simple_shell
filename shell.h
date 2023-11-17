#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdarg.h>

#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t \r \n \a"

extern char **environ;

char *read_commands();
char **tokenize_commands(char *line);
int execute_commands(char **command);
int change_dir(char **args);
int file_exists(const char *filename);
int str_cmp(const char *str1, const char *str2);
char **search_path(char *path);
void print_environment(void);
size_t str_len(const char *str);
char *str_cat(char *destination, const char *source);
char *str_cpy(char *dest, const char *src);
void print_f(const char *format, ...);
char *handle_path(const char *command);

#endif
