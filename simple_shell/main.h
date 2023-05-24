#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>

#include <sys/wait.h>
#define BUFFER_SIZE 1024
#define ARGS_SIZE 64
#define ARGS_ALIASES 64
#define ARGS_ALIAS_LENGTH 128

extern char **environ;
/**
 *
 * size_t _strlen(char *a);
 * int is_setenv_command(const char *command);
 * int is_unsetenv_command(const char *command);
 * void execute_exit_user_input(char **argw, int argd);
 * void execute_setenv_command(char **argw, int argd);
 * void execute_unsetenv_command(char **argw, int argd);
 */

#endif
