/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:10:36 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/19 20:44:01 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"	

static int	sep_outq(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (out_quotes(s[i]))
			return (1);
		else
			i++;
	}
	return (0);
}

static int	seps_alone(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((!ft_strchr(s[i], '<') && !ft_strchr(s[i], '>')
				&& !ft_strchr(s[i], '|')) || only_sep(s[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	need_split(char **s)
{
	int	i;

	i = 0;
	while (s[i]) // check string by string if the **s includes some separator: <, > OR |
	{
		if (!ft_strchr(s[i], '<') && !ft_strchr(s[i], '>')
			&& !ft_strchr(s[i], '|'))
			i++;
		else
			break ;
	}
	if (s[i] == NULL)
		return (0);
	if (seps_alone(s)) //check if seps are alone so would need no split
		return (0);
	if (!sep_outq(s))
		return (0);
	return (1);
}
