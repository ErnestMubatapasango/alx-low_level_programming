#include "main.h"
/**
 * read_user_input - read input
 * @line: input value
 * @fe: input value
 * Return: value
 */
int read_user_input(int fe, char *line)
{
int i = 0;
char ch;
ssize_t read_size;

while ((read_size = read(fe, &ch, 1)) > 0)
{
if (ch == '\n')
{
line[i] = '\0';
return (1);
}
line[i++] = ch;
}

return (read_size != -1);
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
char *token;
int token_start = -1;

for (int j = 0; line[j] != '\0'; j++)
{
if (line[j] == ' ')
{
if (token_start != -1)
{
line[j] = '\0';
argw[i++] = &line[token_start];
token_start = -1;
}
}
else if (token_start == -1)
{
token_start = j;
}
}

if (token_start != -1)
{
argw[i++] = &line[token_start];
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
pid_t pid = fork();

if (pid < 0)
{
char error[] = "fork error\n";
int len = sizeof(error) - 1;
write(STDERR_FILENO, error, len);
_exit(1);
}
else if (pid == 0)
{
if (execvp(argw[0], argw) < 0)
{
char error[] = "execvp error\n";
int len = sizeof(error) - 1;
write(STDERR_FILENO, error, len);
_exit(1);
}
}
else
{
int status;
waitpid(pid, &status, 0);
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
char *commands[ARGS_ARGS];
int command_count = 0;

while (1)
{
char prompt[] = "shell$ ";
int len = sizeof(prompt) - 1;
write(STDOUT_FILENO, prompt, len);

if (!read_user_input(STDIN_FILENO, line))
break;

char *token;
token = line;

while (*token != '\0' && command_count < ARGS_ARGS)
{
if (*token == ';')
{
*token = '\0';
commands[command_count++] = line;
line = token + 1;
}
token++;
}

commands[command_count++] = line;

int previous_status = 0;

for (int i = 0; i < command_count; i++)
{
char *command = commands[i];
char *argw[ARGS_ARGS];
int argd;

parse_user_input(command, argw, &argd);

if (argd > 0)
{
if (argw[0][0] == 'e' && argw[0][1] == 'x' && argw[0][2] == 'i' && argw[0][3] == 't' && argw[0][4] == '\0')
{
_exit(0);
}
else if (argw[0][0] == '&' && argw[0][1] == '&')
{
if (previous_status == 0)
{
execute_command(argw + 1);
previous_status = 0;
}
else
{
previous_status = 1;
}
}
else if (argw[0][0] == '|' && argw[0][1] == '|')
{
if (previous_status != 0)
{
execute_command(argw + 1);
previous_status = 0;
}
else
{
previous_status = 1;
}
}
else
{
execute_command(argw);
previous_status = 0;
}
}
}

command_count = 0;
}

return (0);
}

