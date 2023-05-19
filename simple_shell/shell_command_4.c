#include "main.h"
/**
 * prompt - Prints a prompt to the standard output
 */
void prompt(void)
{
char prompt[] = "$ ";
int i = 0;
while (prompt[i] != '\0')
{
write(STDOUT_FILENO, &prompt[i], 1);
i++;
}
}
/**
 * execute_user_input -  tokenize
 * @user_input: input given by the user
 */
void execute_user_input(char *user_input)
{
char *args[ARGS_SIZE] = {NULL};
int arg_count = 0;
char *token = user_input;
while (*token != ' ' && *token != '\0' && arg_count < ARGS_SIZE - 1)
{
args[arg_count++] = token;
while (*token != ' ' && *token != '\0')
{
token++;
}
if (*token != '\0')
{
*token = '\0';
token++;
}
}
execvp(args[0], args);
perror("execvp error");
exit(EXIT_FAILURE);
}
/**
 * is_exit_input -  tokenize
 * @user_input: input given by the user
 * Return: value
 */
int is_exit_input(char *user_input)
{
char exit_input[] = "exit";
int i = 0;
while (user_input[i] == exit_input[i] && user_input[i] != '\0')
{
i++;
}
return (user_input[i] == '\0' && exit_input[i] == '\0');
}
/**
 * is_env_input - tokenize
 * @user_input: input given by the user
 * Return: value
 */
int is_env_input(char *user_input)
{
char env_input[] = "env";
int i = 0;
while (user_input[i] == env_input[i] && user_input[i] != '\0')
{
i++;
}
return (user_input[i] == '\0' && env_input[i] == '\0');
}
/**
 * handle_exit - exit command
 */
void handle_exit(void)
{
exit(EXIT_SUCCESS);
}
/**
 * handle_env - environment variables
 */
void handle_env(void)
{
char **env = environ;
while (*env != NULL)
{
int i = 0;
while ((*env)[i] != '\0')
{
write(STDOUT_FILENO, &((*env)[i]), 1);
i++;
}
write(STDOUT_FILENO, "\n", 1);
env++;
}
}
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
char input_buffer[BUFFER_SIZE];
ssize_t nread;
pid_t child_pid;
int child_status;
while (1)
{
prompt();
nread = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
if (nread == -1)
{
perror("read error");
exit(EXIT_FAILURE);
}
else if (nread == 0)
{
printf("\n");
break;
}
input_buffer[nread - 1] = '\0';
if (access(input_buffer, X_OK) == -1)
{
perror("command does not exist");
continue;
}
if (is_exit_command(input_buffer))
{
handle_exit();
}
if (is_env_command(input_buffer))
{
handle_env();
continue;
}
child_pid = fork();
if (child_pid == -1)
{
perror("fork error");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
execute_command(input_buffer);
exit(EXIT_FAILURE);
}
else
{
waitpid(child_pid, &child_status, 0);
}
}
exit(EXIT_SUCCESS);
}
