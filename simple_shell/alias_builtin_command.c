#include "main.h"
/**
 * struct - name and value declaration
 */
typedef struct
{
char name[MAX_ALIAS_LENGTH];
char value[MAX_ALIAS_LENGTH];
}
Alias;
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
 * @aliases: alias
 * @alias_count: alias count
 */
void execute_command(char **argw, Alias *aliases, int alias_count)
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
for (int i = 0; i < alias_count; i++)
{
if (compare_strings(argv[0], aliases[i].name) == 0)
{
argw[0] = aliases[i].value;
break;
}
}

execvp(argw[0], argw);

char error[] = "execvp error\n";
int len = sizeof(error) - 1;
write(STDERR_FILENO, error, len);
_exit(1);
}
else
{
int status;
waitpid(pid, &status, 0);
}
}
/**
 * print_aliases - print the alias
 * @aliases: aliases
 * @alias_count: alias count
 */
void print_aliases(Alias *aliases, int alias_count)
{
for (int i = 0; i < alias_count; i++)
{
char line[ARGS_ALIAS_LENGTH * 2];
int len = copy_string(line, aliases[i].name);
line[len++] = '=';
len += copy_string(line + len, aliases[i].value);
line[len++] = '\n';
write(STDOUT_FILENO, line, len);
}
}
/**
 * print_alias - print the alias
 * @aliases: aliases
 * @alias_count: alias count
 * @name: name of alias
 */
void print_alias(Alias *aliases, int alias_count, char *name)
{
for (int i = 0; i < alias_count; i++)
{
if (compare_strings(name, aliases[i].name) == 0)
{
char line[ARGS_ALIAS_LENGTH * 2];
int len = copy_string(line, aliases[i].name);
line[len++] = '=';
len += copy_string(line + len, aliases[i].value);
line[len++] = '\n';
write(STDOUT_FILENO, line, len);
return;
}
}
}
/**
 * define_alias - define the alias
 * @aliases: aliases
 * @alias_count: alias count
 * @name: name of Alias
 * @value: value
 */
void define_alias(Alias *aliases, int *alias_count, char *name, char *value)
{
for (int i = 0; i < *alias_count; i++)
{
if (compare_strings(name, aliases[i].name) == 0)
{
copy_string(aliases[i].value, value);
return;
}
}

if (*alias_count >= ARGS_ALIASES)
{
char error[] = "alias: too many aliases\n";
int len = sizeof(error) - 1;
write(STDERR_FILENO, error, len);
return;
}

copy_string(aliases[*alias_count].name, name);
copy_string(aliases[*alias_count].value, value);
(*alias_count)++;
}
/**
 * compare_strings -  tokenize
 * @str1: input given by the user
 * @str2: local
 * Return: value
 */
int compare_strings(char *str1, char *str2)
{
while (*str1 && *str2 && *str1 == *str2)
{
str1++;
str2++;
}

return (*str1 - *str2);
}
/**
 * copy_string -  tokenize
 * @dest: input given by the user
 * @src: local
 * Return: value
 */
int copy_string(char *dest, char *src)
{
int i = 0;

while (*src)
{
*dest = *src;
dest++;
src++;
i++;
}

*dest = '\0';

return (i);
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
char *argw[ARGS_ARGS];
int argd;
Alias aliases[ARGS_ALIASES];
int alias_count = 0;

while (1)
{
write(STDOUT_FILENO, "$ ", 2);

if (!read_user_input(STDIN_FILENO, line))
{
break;
}

parse_user_input(line, argw, &argd);

if (argd > 0)
{
if (compare_strings(argw[0], "alias") == 0)
{
if (argd == 1)
{
print_aliases(aliases, alias_count);
}
else if (argd == 2)
{
print_alias(aliases, alias_count, argw[1]);
}
else
{
for (int i = 1; i < argd; i++)
{
char *name = argw[i];
char *value;
int j;
for (j = 0; argw[i][j] != '\0'; j++)
{
if (argw[i][j] == '=')
{
value = &argw[i][j + 1];
argw[i][j] = '\0';
break;
}
}
if (argw[i][j] == '\0')
{
value = NULL;
}
if (value != NULL)
{
define_alias(aliases, &alias_count, name, value);
}
}
}
}
else
{
execute_command(argw, aliases, alias_count);
}
}
}
return (0);
}

