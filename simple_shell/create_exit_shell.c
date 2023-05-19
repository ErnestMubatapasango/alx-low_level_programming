#include "main.h"
/**
 * read_user_input - read input
 * @line: input value
 * @fe: value
 * Return: value
 */
int read_user_input(int fe, char *line)
{
int pos = 0;
char c;
while (pos < BUFFER_SIZE - 1 && read(fe, &d, 1) > 0)
{
if (d == '\n')
{
line[pos] = '\0';
return (1);
}
line[pos++] = d;
}
line[pos] = '\0';
return (0);
}
/**
 * parse_user_input - parse input
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
argv[i][arg_pos] = '\0';
i++;
arg_pos = 0;
is_arg = 0;
}
}
else
{
if (!is_arg)
{
argw[i] = malloc((ARGS_ARGS + 1) * sizeof(char));
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
 * execute_user_input -  tokenize
 * @argw: input given by the user
 */
void execute_user_input(char **argw)
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
 * parse_exit_status -  tokenize
 * @arg: input given by the user
 * Return: value
 */
int parse_exit_status(char *arg)
{
int status = 0;
int i = 0;
while (arg[i])
{
if (arg[i] < '0' || arg[i] > '9')
{
char error[] = "Invalid exit status\n";
write(STDERR_FILENO, error, sizeof(error) - 1);
exit(EXIT_FAILURE);
}
status = (status * 10) + (arg[i] - '0');
i++;
}
return (status);
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
if (*str1 == '\0' && *str2 == '\0')
{
return (0);
}
else if (*str1 == '\0')
{
return (-1);
}
else if (*str2 == '\0')
{
return (1);
}
else if (*str1 < *str2)
{
return (-1);
}
else
{
return (1);
}
}
/**
 * is_builtin_exit -  builtin exit
 * @command: input given by the user
 * Return: value
 */
int is_builtin_exit(const char *command)
{
const char *exit_command = "exit";
int i = 0;

while (command[i] && exit_command[i])
{
if (command[i] != exit_command[i])
{
return (0);
}
i++;
}
return (exit_command[i] == '\0');
}
/**
 * execute_builtin_exit -  builtin exit
 * @argw: local argument
 * @argd: second local argument
 *
 */
void execute_builtin_exit(char **argw, int argd)
{
if (argd == 1)
{
exit(EXIT_SUCCESS);
}
else if (argd == 2)
{
int status = parse_exit_status(argw[1]);
exit(status);
}
else
{
char error[] = "Usage: exit [status]\n";
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
char *argv[ARGS_ARGS + 1];
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
if (is_builtin_exit(argw[0]))
{
execute_builtin_exit(argw, argd);
}
else
{
execute_user_input(argw);
}
}
for (int i = 0; i < argd; i++)
{
free(argw[i]);
}
}
return (0);
}


