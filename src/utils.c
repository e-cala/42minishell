/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:52:38 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/22 20:49:39 by erosas-c         ###   ########.fr       */
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

int	sep_betq(char *p)
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

int	out_quotes(char *s)
{
	if (!ft_strchr(s, '<') && !ft_strchr(s, '>') && !ft_strchr(s, '|'))
		return (0);
	else if (!ft_strchr(s, SQUOTE) && !ft_strchr(s, DQUOTE))
		return (1);
	else if (sep_betq(s))
		return (0);
	else
		return (1);
}

int	splitable(char *s)
{
	if ((!ft_strchr(s, '<') && !ft_strchr(s, '>')
				&& !ft_strchr(s, '|')) || only_sep(s))
		return (0);
	else if (!out_quotes(s))
		return (0);
	return (1);
}

int	count_new_ptrs(char **s)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (s[i])
	{
		if ((!ft_strchr(s[i], '<') && !ft_strchr(s[i], '>')
				&& !ft_strchr(s[i], '|')) || only_sep(s[i]))
			i++;
		else
		{
			num++;
			i++;
		}
	}
	return (num);
}
