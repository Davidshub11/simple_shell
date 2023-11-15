#include "shell.h"
/**
 * clays_prompt - prompting command
 *
 */
void clays_prompt(void)
{
	char clays_wdir[1024];

	if (getcwd(clays_wdir, sizeof(clays_wdir)) == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	clays_printf(clays_wdir);
	clays_printf(" ~> ");
}

