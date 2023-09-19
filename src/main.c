/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:38:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/15 20:43:18 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"
#include <errno.h>


/*
int main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;
	(void)envp;
	static char *line = NULL;
	loop_prompt(line);
	return(0);
}*/

int main(int argc, char **argv,char **envp)
{
	(void)envp;
	int algo = 1;
	if (ft_strncmp(argv[argc - 1], "cd", ft_strlen(argv[argc - 1])) != 0)
	{
		//TODO GESTION DE ERRORES EN LA ENTRADA
		printf("%d", errno);
		//printf("\nError Message: %s",strerror(errno));
	}
	return (0);
}
