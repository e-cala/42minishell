/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:07:30 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/26 12:19:47 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"	

int	some_virg_outq(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (p[i] == '~')
			return (1);
		else if (p[i] == SQUOTE)
			i = next_quote(p, i, SQUOTE);
		else if (p[i] == DQUOTE)
			i = next_quote(p, i, DQUOTE);
		else
			i++;
	}
	return (0);
}

int	expandable(char *s)
{
	if (!ft_strchr(s, '~'))
		return (0);
	else if (!ft_strchr(s, SQUOTE) && !ft_strchr(s, DQUOTE))
		return (1);
	else if (some_virg_outq(s))
		return (1);
	else
		return (0);
}

int	need_expand(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (expandable(s[i]))
			return (1);
		else
			i++;
	}
	return (0);
}
