/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:38:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/08 21:17:05 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

int	main(void)
{
	//readl_test();
	char	cmd[100] = "echo \"hello      there\" how are 'you 'doing? $USER |wc -l >outfile";
	char	**trimmed;
	char	**subsplitted;
	int	i = 0;

	trimmed = cmdtrim(cmd);
	while (trimmed[i])
	{
		printf("trimmed[%i]: %s\n", i, trimmed[i]);
		i++;
	}
	subsplitted = cmdsubsplit(trimmed, i);
	free_all(trimmed, i - 1);
	
	return (0);
}
