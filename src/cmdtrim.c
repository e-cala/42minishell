/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:42:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/08/04 17:43:15 by yourLogin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

static int	ft_ptr_len(char const *p)
{
	int	i;

	i = 0;
	if (p[i++] == DQUOTE)
	{
		while (p[i] != DQUOTE)
			i++;
		i++;
	}
	else
		while (p[i] != SPACE && p[i])
			i++;
	return (i);
}

int	ft_str_count(char *s)
{
	int	str_count;
	int	j;

	str_count = 0;
	j = 0;
	if (*s == '\0')
		return (0);
	while (s[j])
	{
		while (s[j] && s[j] == SPACE)
			j++;
		if (s[j] == DQUOTE)
		{
			str_count++;
			j++;
			while (s[j] && s[j] != DQUOTE)
				j++;
			if (s[j] == DQUOTE)
				j++;
		}
		else if (s[j])
		{
			str_count++;
			while (s[j] && s[j] != SPACE && s[j] != DQUOTE)
				j++;
		}
	}
	return (str_count);
}

char	**cmdtrim(char *s)
{
	int		str_count;
	char	**res;
	int		n;
	char	*p;

	p = NULL;
	n = 0;
	if (!s)
		return (NULL);
	str_count = ft_str_count(s);
	res = malloc (sizeof(char *) * (str_count + 1));
	if (!res)
		return (NULL);
	while (n < str_count)
	{
		p = find_ptr(s, SPACE);
		res[n] = ft_substr(p, 0, ft_ptr_len(p));
		if (res[n] == NULL)
			return (free_all(res, n));
		n++;
		s = s + (p - s) + ft_ptr_len(p);
	}
	res[n] = NULL;
	return (res);
}
