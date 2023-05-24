#include "main.h"

void _write(int fd, const char *buffer);
void _read(int fd, char *buffer, size_t count);
size_t _strlen(const char *str);
void _strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
char *_strtok(char *str, const char *delim);
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
int is_interactive = isatty(STDIN_FILENO);
char *token;
int i = 0;
while (running)
{
if (is_interactive)
_write(STDOUT_FILENO, "($) ");
_read(STDIN_FILENO, buffer, BUFFER_SIZE);
buffer[_strlen(buffer) - 1] = '\0';
token = _strtok(buffer, " ");

while (token != NULL && i < (BUFFER_SIZE / 2 - 1))
{
args[i] = token;
token = _strtok(NULL, " ");
i++;
}
args[i] = NULL;

if (_strcmp(args[0], "exit") == 0)
running = 0;
else
{
pid_t pid = fork();
if (pid < 0)
{
_write(STDERR_FILENO, "Fork failed\n");
_exit(1);
}
else if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
_write(STDERR_FILENO, "Execution failed\n");
_exit(1);
}
}
else
{
waitpid(pid, NULL, 0);
}
}
}
return (0);
}
/**
 * _write - write command
 * @fd: fd
 * @buffer: buffer
 */
void _write(int fd, const char *buffer)
{
size_t len = _strlen(buffer);
write(fd, buffer, len);
}
/**
 * _read - read
 * @fd: fd
 * @buffer: buffer
 * @count: count
 */
void _read(int fd, char *buffer, size_t count)
{
read(fd, buffer, count);
}
/**
 * _strlen  - length
 * @str: str
 * Return: value
 */
size_t _strlen(const char *str)
{
const char *s = str;
while (*s)
++s;
return (s - str);
}
/**
 * _strcpy - string copy
 * @dest: dest
 * @src: src
 */
void _strcpy(char *dest, const char *src)
{
while (*src)
*dest++ = *src++;
*dest = '\0';
}
/**
 * _strcmp - string compare
 * @str1: str1
 * @str2: str2
 * Return: value
 */
int _strcmp(const char *str1, const char *str2)
{
while (*str1 && (*str1 == *str2))
{
++str1;
++str2;
}
return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
/**
 * _strtok - striiing tokenize
 * @str: str
 * @delim: delim
 * Return: value
 */
char *_strtok(char *str, const char *delim)
{
static char *prev;
char *start = prev;
char *end = start;

if (str != NULL)
prev = str;

if (prev == NULL || *prev == '\0')
return (NULL);

while (*end)
{
if (*end == *delim)
{
*end = '\0';
prev = end + 1;
if (start != end)
return (start);
else
start = prev;
}
++end;
}
prev = NULL;
return (start);
}

