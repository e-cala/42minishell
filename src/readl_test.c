#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int	main(void)
{
	char	*input;

	input = readline("Escriu alguna cosa: ");
	printf("Has escrit: %s\n", input);

	free(input);

	return (0);
}
