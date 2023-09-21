#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

char	*rl_gets(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	line = readline("minishell- ");
	if (line && *line)
		add_history(line);
	return (line);
}


void	loop_prompt(char *line)
{
	if (line == NULL)
	{
		line = rl_gets(line);
		test(line);			// Change test function
	}
	while (ft_strncmp(line, "exit", 4) != 0)
	{
		line = rl_gets(line);
		test(line);			// Change test function
	}
	free(line);
	return ;
}