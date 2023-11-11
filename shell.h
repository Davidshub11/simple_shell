#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <fcntl.h>
void clays_cmds(char **clays_cmds, size_t *clays_size);
void clays_env(char **clays_env);
ssize_t clays_getline(char **clays_buf, size_t *clays_size);
void clays_prompt(void);
int clays_putchar(char clays_char);
int clays_putchar(char clays_char);
void clays_executor(const char *clays_cmd_line);
int clays_printf(const char *claysstring);
#endif
