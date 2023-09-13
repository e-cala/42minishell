/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:38:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/13 19:00:26 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		printf("%s\n",cmdtrim(line)[0]); //have to make it print the first time we write it
	}
	while (ft_strncmp(line, "exit", 4) != 0)
	{
		line = rl_gets(line);
		printf("%s\n",cmdtrim(line)[0]); //have to make it print the first time we write it
	}
	free(line);
	return ;
}

int main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;
	(void)envp;
	static char *line = NULL;
	loop_prompt(line);
	return(0);
}
/*
int	main(void)
{
	char	cmd[100] = "echo \"hello      there\" how are 'you 'doing? $USER |wc -l <outfile";
	char	**trimmed;
	char	**subsplitted;
	char	**parsed;
	int		i = 0;

	trimmed = cmdtrim(cmd);
	while (trimmed[i])
		i++;
	{
		printf("trimmed[%i]: %s\n", i, trimmed[i]);
		i++;
	}
	subsplitted = cmdsubsplit(trimmed, i);
	free_all(trimmed, i - 1);
	i = 0;
	while (subsplitted[i])
	{
		printf("subsplitted[%i]: %s\n", i, subsplitted[i]);
		i++;
	}
	i = 0;
	while (subsplitted[i])
	{
		printf("subsplitted[%i]: %s\n", i, subsplitted[i]);
		i++;
	}
	i = 0;
	if (incl_envvar(subsplitted) == 1)
	{	
		parsed = parser(subsplitted, i);
		free_all(subsplitted, i - 1);
	}

	return (0);
}*/
