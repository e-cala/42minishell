/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:38:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/08/04 17:39:15 by yourLogin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	**cmdtrim(char *s);

int	main(void)
{
	char	cmd[100] = "echo \"hello      there\" how are 'you 'doing? $USER |wc -l >outfile";
	char	**trimmed;
	int	i = 0;
	
	trimmed = cmdtrim(cmd);
	while (trimmed[i])
	{
		printf("trimmed[%i]: %s\n", i, trimmed[i]);
		i++;
	}
	return (0);
}
