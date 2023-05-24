#include "main.h"

void read_user_input(char *buffer);
void execute_command(char **args);
void parse_user_input(char *buffer, char **args);
int string_length(const char *str);
int string_compare(const char *str1, const char *str2);
void write_output(const char *str);
/**
 * main - Entry point
 *
 * Description: Simple shell program that reads commands from standard input
 * and executes them using the execve system call.
 *
 * Return: Always 0
 */
int main(void)
{
char buffer[BUFFER_SIZE];
char *args[BUFFER_SIZE / 2];
int running = 1;

while (running)
{
write_output("($) ");
read_user_input(buffer);
parse_user_input(buffer, args);

if (args[0] == NULL)
continue;

if (string_compare(args[0], "exit") == 0)
running = 0;
else
execute_command(args);
}

return (0);
}
/**
 * read_user_input - read user input
 * @buffer: buffer
 */
void read_user_input(char *buffer)
{
ssize_t bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (bytesRead == -1)
{
write_output("Read failed\n");
_exit(1);
}
buffer[bytesRead - 1] = '\0';
}
/**
 * string_length - read user input
 * @str: buffer
 * Return: value
 */
int string_length(const char *str)
{
int len = 0;
while (str[len] != '\0')
len++;
return (len);
}
/**
 * string_compare - read user input
 * @str1: buffer
 * @str2: str2
 * Return: value
 */
int string_compare(const char *str1, const char *str2)
{
int i = 0;
while (str1[i] == str2[i])
{
if (str1[i] == '\0')
return (0);
i++;
}
return (str1[i] - str2[i]);
}
/**
 * write_output - read user input
 * @str: buffer
 */
void write_output(const char *str)
{
ssize_t bytesWritten = write(STDOUT_FILENO, str, string_length(str));
if (bytesWritten == -1)
{
write(STDERR_FILENO, "Write failed\n", 13);
_exit(1);
}
}
/**
 * parse_user_input - read user input
 * @buffer: buffer
 * @args: args
 */
void parse_user_input(char *buffer, char **args)
{
int i = 0;
char *token;

token = strtok(buffer, " ");
while (token != NULL)
{
args[i] = token;
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;
}
/**
 * execute_command - read user input
 * @args: buffer
 */
void execute_command(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid < 0)
{
write_output("Fork failed\n");
_exit(1);
}
else if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
write_output("Execution failed\n");
_exit(1);
}
}
else
{
waitpid(pid, &status, 0);
}
}

