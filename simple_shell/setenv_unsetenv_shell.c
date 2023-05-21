#include "main.h"

extern char **environ;
/**
 * read_input_input - read input
 * @line: input value
 * @fe: input value
 * Return: value
 */
int read_user_input(int fe, char *line)
{
int pos = 0;
char c;

while (pos < BUFFER_SIZE - 1 && read(fe, &c, 1) > 0)
{
if (c == '\n')
{
line[pos] = '\0';
return (1);
}
line[pos++] = c;
}

line[pos] = '\0';
return (0);
}
/**
 * parse_user_input - function prototype
 * @line: input given by the user
 * @argw: argw
 * @argd: argd
 */
void parse_user_input(char *line, char **argw, int *argd)
{
int i = 0;
int arg_pos = 0;
int is_arg = 0;

while (*line)
{
if (*line == ' ')
{
if (is_arg)
{
argw[i][arg_pos] = '\0';
i++;
arg_pos = 0;
is_arg = 0;
}
}
else
{
if (!is_arg)
{
argw[i] = (char *)malloc((ARGS_ARGS + 1) * sizeof(char));
is_arg = 1;
}
argw[i][arg_pos++] = *line;
}

line++;
}

if (is_arg)
{
argw[i][arg_pos] = '\0';
i++;
}

argw[i] = NULL;
*argd = i;
}
/**
 * execute_command - parse input
 * @argw: argw
 */
void execute_command(char **argw)
{
int pid = fork();
if (pid < 0)
{
char error[] = "Fork error\n";
write(STDERR_FILENO, error, sizeof(error) - 1);
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execvp(argw[0], argw) < 0)
{
char error[] = "Execution error\n";
write(STDERR_FILENO, error, sizeof(error) - 1);
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
}
/**
 * compare_strings -  tokenize
 * @str1: input given by the user
 * @str2: local
 * Return: value
 */
int compare_strings(const char *str1, const char *str2)
{
while (*str1 && *str2 && *str1 == *str2)
{
str1++;
str2++;
}

return (*str1 == '\0' && *str2 == '\0');
}
/**
 * is_exit_command -  exit command execution
 * @command: input given by the user
 * Return: value
 */
int is_exit_command(const char *command)
{
const char *exit_command = "exit";
return (compare_strings(command, exit_command));
}
/**
 * is_setenv_command -  set the command environment variable
 * @command: input given by the user
 * Return: value
 */
int is_setenv_command(const char *command)
{
const char *setenv_command = "setenv";
return (compare_strings(command, setenv_command));
}
/**
 * is_unsetenv_command -  unset the command environment variable
 * @command: input given by the user
 * Return: value
 */
int is_unsetenv_command(const char *command)
{
const char *unsetenv_command = "unsetenv";
return (compare_strings(command, unsetenv_command));
}
/**
 * execute_exit_user_input -  tokenize
 * @argw: input given by the user
 * @argd: input given by the user
 */
void execute_exit_user_input(char **argw, int argd)
{
if (argd == 1)
{
exit(EXIT_SUCCESS);
}
else if (argd == 2)
{
int status = atoi(argw[1]);
exit(status);
}
else
{
char error[] = "Usage: exit [status]\n";
write(STDERR_FILENO, error, sizeof(error) - 1);
}
}
/**
 * execute_setenv_command -  tokenize
 * @argw: input given by the user
 * @argd: input given by the user
 */
void execute_setenv_command(char **argw, int argd)
{
if (argd != 3)
{
char error[] = "Usage: setenv VARIABLE VALUE\n";
write(STDERR_FILENO, error, sizeof(error) - 1);
return;
}

if (setenv(argw[1], argw[2], 1) < 0)
{
char error[] = "Setenv error\n";
write(STDERR_FILENO, error, sizeof(error) - 1);
}
}
/**
 * execute_unsetenv_command -  tokenize
 * @argw: input given by the user
 * @argd: input given by the user
 */
void execute_unsetenv_command(char **argw, int argd)
{
if (argd != 2)
{
char error[] = "Usage: unsetenv VARIABLE\n";
write(STDERR_FILENO, error, sizeof(error) - 1);
return;
}

if (unsetenv(argw[1]) < 0)
{
char error[] = "Unsetenv error\n";
write(STDERR_FILENO, error, sizeof(error) - 1);
}
}
/**
 * main - Entry point
 * Description: Simple shell program that reads commands from standard input
 * and executes them using the execve system call.
 * Return: Always 0
 */
int main(void)
{
char line[BUFFER_SIZE];
char *argw[ARGS_ARGS + 1];
int argd;

while (1)
{
char prompt[] = "shell$ ";
write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

if (!read_user_input(STDIN_FILENO, line))
break;

parse_user_input(line, argw, &argd);

if (argd > 0)
{
if (is_exit_command(argw[0]))
{
execute_exit_user_input(argw, argd);
}
else if (is_setenv_command(argw[0]))
{
execute_setenv_command(argw, argd);
}
else if (is_unsetenv_command(argw[0]))
{
execute_unsetenv_command(argw, argd);
}
else
{
execute_command(argw);
}
}
for (int i = 0; i < argd; i++)
{
free(argw[i]);
}
}
return (0);
}

