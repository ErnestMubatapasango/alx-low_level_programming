#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program.
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: a pointer to a new string, or NULL if it fails
 */

char *argstostr(int ac, char **av)
{
int i, str_index = 0, arg_index = 0, total_length = 0, arg_length = 0;
char *str;
if (ac == 0 || av == NULL)
{
return (NULL);
}
for (i = 0; i < ac; i++)
{
while (av[i][arg_length] != '\0')
{
arg_length++;
}
total_length += arg_length + 1;
}
str = malloc(total_length *sizeof(char));
if (str == NULL)
{
return (NULL);
}
for (i = 0; i < ac; i++)
{
while (av[i][arg_index] != '\0')
{
str[str_index] = av[i][arg_index];
arg_index++;
str_index++;
}
str[str_index] = '\n';
str_index++;
}
str[str_index] = '\0';
return (str);
}

