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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_substring(char *s, unsigned int start, size_t len);

static char	*ft_find_ptr(char *p)
{
	while (*p == ' '  && *p)
		p++;
	return (p);
}

static int	ft_ptr_len(char const *p)
{
	int	i;

	i = 0;
	if (p[0] == 34)
	{
		i++;
		while (p[i] != 34)
			i++;
		i++;
	}
	else
	{
		while (p[i] != ' ' && p[i])
			i++;
	}
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
		while (s[j] && s[j] == ' ')
			j++;
		if (s[j] == 34)
		{
			str_count++;
			j++;
			while (s[j] && s[j] != 34)
				j++;
			if (s[j] == 34)
				j++;
		}
		else if (s[j])
		{
			str_count++;
			while (s[j] && s[j] != ' ' && s[j] != 34)
				j++;
		}
	}
	return (str_count);
}

char	**free_all(char	**res, int n)
{
	while (n >= 0)
	{
		free(res[n]);
		n--;
	}
	free(res);
	return (NULL);
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
		p = ft_find_ptr(s);
		res[n] = ft_substring(p, 0, ft_ptr_len(p));
		if (res[n] == NULL)
			return (free_all(res, n));
		n++;
		s = s + (p - s) + ft_ptr_len(p);
	}
	res[n] = NULL;
	return (res);
}
