#include "../includes/minishell.h"

int	readl_test(void)
{
	char	*input;

	input = readline("Escriu alguna cosa: ");
	printf("Has escrit: %s\n", input);

	free(input);

	return (0);
}
