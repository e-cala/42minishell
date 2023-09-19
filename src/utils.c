/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:52:38 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/19 20:25:41 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

/*bool tern_true(int condition)
{
	if (condition == TRUE)
		return (true);
	return (false);
}*/

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

/*
 *
 * */
int	only_sep(char *s)
{
	//tern_true(ft_strlen(s) > 2 && (ft_strchr(s, '<') || ft_strchr(s, '>')))
	if (ft_strlen(s) > 2 && (ft_strchr(s, '<') || ft_strchr(s, '>')))
		return (0);
	else if (ft_strlen(s) > 1 && ft_strchr(s, '|'))
		return (0);
	else if (ft_strlen(s) == 2 && ft_strchr(s, '<') && s[0] != s[1])
		return (0);
	else if (ft_strlen(s) == 2 && ft_strchr(s, '>') && s[0] != s[1])
		return (0);
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
