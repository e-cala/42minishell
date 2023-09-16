/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:10:36 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/16 14:24:15 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

	
	
/*static int	sep_inq(char *p)
{
	


	return (0);
}*/

static int	seps_alone(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strchr(s[i], SQUOTE) && !ft_strchr(s[i], DQUOTE))
		{
			if (ft_strlen(s[i]) > 2 && ft_strchr(s[i], '<'))
				return (0);
			else if (ft_strlen(s[i]) > 2 && ft_strchr(s[i], '>'))
				return (0);
			else if (ft_strlen(s[i]) > 1 && ft_strchr(s[i], '|'))
				return (0);
			else if (ft_strlen(s[i]) == 2 && ft_strchr(s[i], '<')
				&& s[i][0] != s[i][1])
				return (0);
			else if (ft_strlen(s[i]) == 2 && ft_strchr(s[i], '>')
				&& s[i][0] != s[i][1])
				return (0);
		}
		i++;
	}
	return (1);
}

static int	incl_sep(char **s)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (s[len] != NULL)
		len++;
	while (s[i]) // check string by string if the **s includes some separator: <, > OR |
	{
		if (!ft_strchr(s[i], '<') && !ft_strchr(s[i], '>') && !ft_strchr(s[i], '|'))
			i++;
	}
	if (i != len)
		return (1);
	return (0);
}

int	need_split(char **s)
{
	int	i;

	i = 0;
	if (!incl_sep(s)) //check if the **s includes some separator: <, > OR |
		return (0);
	if (seps_alone(s)) //check if seps are alone so would need no split
		return (0);
/*	if (!sep_inq(s[i]))
		return (1);*/
	return (1);
//	return (0);
}

