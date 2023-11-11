#include "shell.h"
/**
 * clays_cmds - main command entry
 * @clays_cmds: cmd parsed into the functions
 * @clays_size: size of command parsed into the function
 */
void clays_cmds(char **clays_cmds, size_t *clays_size)
{
	ssize_t clays_read;

	clays_read = clays_getline(clays_cmds, clays_size);

	if (clays_read == -1)
	{
		if (*clays_cmds == NULL)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		if (feof(stdin))
		{
			clays_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	if ((*clays_cmds)[clays_read - 1] == '\n')
	{
		(*clays_cmds)[clays_read - 1] = '\0';
		*clays_size = strlen(*clays_cmds);
	}
}

