#include "shell.h"

/**
 * main - main__programs to be executed
 * @argc: counting of argumen to be executed
 * @argv: argum_var in the main function
 * @env: env_enviroment in the kernel
 * Return: 0 or 1
 */
int main(int argc, char *argv[], char **env)
{

	char *clays_cmd;
	size_t clays_size;
	int clays_exitstatus;
	size_t clays_newlinepos;
	(void)argv;
	(void)argc;

	clays_cmd = NULL;
	clays_exitstatus = 0;

	while (1)
	{
		if (isatty(0) == 1)
			clays_prompt();
		clays_cmds(&clays_cmd, &clays_size);

		if (strcmp(clays_cmd, "exit") == 0)
		{
			break;
		}
		else if (strncmp(clays_cmd, "exit ", 5) == 0)
		{
			clays_exitstatus = atoi(clays_cmd + 5);
			break;
		}
		else if (strcmp(clays_cmd, "env") == 0 || strcmp(clays_cmd, "printenv") == 0)
			clays_env(env);
		clays_executor(clays_cmd);

		clays_newlinepos = strcspn(clays_cmd, "\n");
		if (clays_newlinepos < clays_size)
			clays_cmd[clays_newlinepos] = '\0';

		if (clays_cmd != NULL)
			clays_cmd = NULL;
	}

	return (clays_exitstatus);
}

