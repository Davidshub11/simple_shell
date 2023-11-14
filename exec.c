#include "shell.h"

/**
 * clays_executor - exect commds being passed
 * @clays_cmd_line: line cmd
 */
void clays_executor(const char *clays_cmd_line);
void clays_executor(const char *clays_cmd_line)
{
	char *clays_args[128];
	int clays_argument_count = 0;
	char *clays_delim = " \n\t";
	char *clays_myenv[] = {NULL};
	pid_t clays_pid = fork();

	if (clays_pid == -1)
	{
		perror("fork Error");
		exit(EXIT_FAILURE);
	}
	else if (clays_pid == 0)
	{
		char *clays_token = strtok((char *)clays_cmd_line, clays_delim);

		while (clays_token != NULL)
		{
			clays_args[clays_argument_count++] = clays_token;
			clays_token = strtok(NULL, clays_delim);
		}
		clays_args[clays_argument_count] = NULL;

		if (strcmp(clays_args[0], "clear") == 0)
		{
			if (system("clear") == -1)
			{
				perror("clear");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		if (strchr(clays_args[0], '/') != NULL)
		{
			if (execve(clays_args[0], clays_args, clays_myenv) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *clays_pathenvs = getenv("PATH");
			char *clays_pathcpy = strdup(clays_pathenvs);
			char *clays_path = strtok(clays_pathcpy, ":");

			free(clays_pathcpy);
			while (clays_path != NULL)
			{
				char clays_fullpth[256];

				snprintf(clays_fullpth, sizeof(clays_fullpth), "%s/%s", clays_path, clays_args[0]);
				if (execve(clays_fullpth, clays_args, clays_myenv) != -1)
				{
					exit(EXIT_SUCCESS);
				}
				clays_path = strtok(NULL, ":");
			}

			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

