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
	line = readline("minishell~ ");
	if (line && *line)
		add_history(line);
	return (line);
}

void	loop_prompt(char *line)
{
	int i = 0;
//	int j = 0;

	if (line == NULL)
	{
		line = rl_gets(line);
		while (cmdtrim(line)[i])
		{
			printf("%s\n", cmdtrim(line)[i]); //have to make it print the first time we write it
			i++;
		}
		cmdsubsplit(cmdtrim(line), i);
	/*	while (cmdsubsplit(cmdtrim(line), i)[j])
		{
			printf("%s\n", cmdsubsplit(cmdtrim(line), i)[j]); //have to make it print the first time we write it
			j++;
		}*/
	}
	while (ft_strncmp(line, "exit", 4) != 0)
	{
		line = rl_gets(line);
		i = 0;
	//	j = 0;
		while (cmdtrim(line)[i])
		{
			printf("%s\n", cmdtrim(line)[i]); //have to make it print the first time we write it
			i++;
		}
		cmdsubsplit(cmdtrim(line), i);
		/*while (cmdsubsplit(cmdtrim(line), i)[j])
		{
			printf("%s\n", cmdsubsplit(cmdtrim(line), i)[j]); //have to make it print the first time we write it
			j++;
		}*/
	}
	free(line);
	return ;
}