/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:42:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/08 22:18:26 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

static char	**trimtosplit(char **trm, char **spl)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	printf("enters trimtosplit\n");
	while (trm[i])
	{
		printf("trm[%i][0]: %c, trm[%i][1]: %c\n", i, trm[i][0], i, trm[i][1]);
		if (trm[i][0] != '<' && trm[i][0] != '>' && trm[i][0] != '|')
		{
			printf("IF\n");
			spl[j] = malloc (sizeof(char) * (ft_strlen(trm[i]) + 1));
			if (!spl[j])
				return (NULL);
			ft_strlcpy(spl[j], trm[i], ft_strlen(trm[i]) + 1);
			printf("spl[%i]: %s\n", j, spl[j]);
		}
		else if (trm[i][0] != trm[i][1])
		{
			printf("ELSE IF\n");
			spl[j] = malloc (sizeof(char) + 1);
			if (!spl[j])
				return (NULL);
			spl[j++] = ft_substr(trm[i], 0, 1);
			spl[j] = malloc (sizeof(char) * (ft_strlen(spl[j])));
			if (!spl[j])
				return (NULL);
			spl[j] = ft_substr(trm[i], 1, ft_strlen(spl[j] - 1));
		}
		else
		{
			printf("ELSE\n");
			spl[j] = malloc (sizeof(char) * 2 + 1);
			if (!spl[j])
				return (NULL);
			spl[j++] = ft_substr(trm[i], 0, 2);
			spl[j] = malloc (sizeof(char) * (ft_strlen(spl[j]) - 1));
			spl[j] = ft_substr(trm[i], 2, ft_strlen(spl[j] - 2));
		}
		j++;
		i++;
	}
	return (spl);
}

static int	count_new_ptrs(char **s)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i][0] == '<' || s[i][0] == '>' || s[i][0] == '|') && ft_strlen(s[i]) > 1)
			num++;
		i++;
	}
	return (num);
}

char		** cmdsubsplit(char **s, int len)
{
	char	**res;

	res = malloc (sizeof(char *) * (count_new_ptrs(s) + len + 1));
	if (!res)
		return (NULL);
	res = trimtosplit(s, res);
	return (res);
}
