/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:38:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/19 21:03:46 by erosas-c         ###   ########.fr       */
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
	int i = 0;
	int j = 0;
	char **cmd;

	if (line == NULL)
	{
		line = rl_gets(line);
		cmd = cmdtrim(line);
		while (cmd[i])
		{
			printf("%s\n", cmd[i]); //have to make it print the first time we write it
			i++;
		}
//		i = 0;
	//	cmdsubsplit(cmdtrim(line), i);
		if (need_split(cmd))
			cmd = cmdsubsplit(cmd, i);
		while (cmd[j])
		{
			printf("%s\n", cmd[j]); //have to make it print the first time we write it
			j++;
		}
	}
	while (ft_strncmp(line, "exit", 4) != 0)
	{
		line = rl_gets(line);
		i = 0;
		j = 0;
		cmd = cmdtrim(line);
		while (cmd[i])
		{
			printf("%s\n", cmd[i]); //have to make it print the first time we write it
			i++;
		}
//		i = 0;
	//	cmdsubsplit(cmdtrim(line), i);
		if (need_split(cmd))
			cmd = cmdsubsplit(cmd, i);
		while (cmd[j])
		{
			printf("%s\n", cmd[j]); //have to make it print the first time we write it
			j++;
		}
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
