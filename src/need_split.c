/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:10:36 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/18 20:31:48 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"	

static int	next_quote(char *p, int i, char c)
{
	i++;
	while (p[i] && p[i] != c)
		i++;
	if (p[i] == c)
		i++;
	return (i);
}

static int	sep_betq(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if ((p[i] == '<' || p[i] == '>' || p[i] == '|'))
			return (0);
		else if (p[i] == SQUOTE)
			i = next_quote(p, i, SQUOTE);
		else if (p[i] == DQUOTE)
			i = next_quote(p, i, DQUOTE);
		else
			i++;
	}
	return (1);
}

static int	sep_outq(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strchr(s[i], '<') && !ft_strchr(s[i], '>')
			&& !ft_strchr(s[i], '|'))
			i++;
		else if (!ft_strchr(s[i], SQUOTE) && !ft_strchr(s[i], DQUOTE))
			return (1);
		else if (sep_betq(s[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

static int	seps_alone(char **s)
{
	int	i;

	i = 0;
	while (s[i])
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
		i++;
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
