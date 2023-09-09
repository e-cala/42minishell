/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:38:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/09 13:01:14 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

int	main(void)
{
	//readl_test();
	char	cmd[100] = "echo \"hello      there\" how are 'you 'doing? $USER |wc -l <outfile";
	char	**trimmed;
	char	**subsplitted;
	int		i = 0;

	trimmed = cmdtrim(cmd);
	while (trimmed[i])
		i++;
	/*{
		printf("trimmed[%i]: %s\n", i, trimmed[i]);
		i++;
	}*/
	subsplitted = cmdsubsplit(trimmed, i);
	free_all(trimmed, i - 1);
	i = 0;
	while (subsplitted[i])
	{
		printf("subsplitted[%i]: %s\n", i, subsplitted[i]);
		i++;
	}
	return (0);
}
