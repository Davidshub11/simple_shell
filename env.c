#include "shell.h"
/**
 * print_env - prints environment variable to stdout
 * @clays_env: envs
 */
void clays_env(char **clays_env)
{
	int clay;

	for (clay = 0; clays_env[clay] != NULL; clay++)
	{
		clays_printf(clays_env[clay]);
		clays_putchar('\n');
	}
}

