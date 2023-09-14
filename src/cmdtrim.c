/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:42:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/14 20:54:17 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

/*static int	ft_upd_je(char *s, int j)
{
	if ((s[j] == '>' && s[j + 1] == '>') || (s[j] == '<' && [j + 1] == '<'))
		j = j + 2;
	else
		j++;
	while (s[j] && s[j] != '<' && s[j] != '>' && s[j] != '|' && s[j] != KSPACE)
		j++;
	else
	{
		while (s[j] && s[j] != KSPACE && s[j] != )
			j++;
	return (j);
}*/

static int	ft_upd_j(char *s, int j, int i)
{
	if (i == 1)
	{
		while (s[j] && s[j] != KSPACE)
			j++;
	}
	else if (s[j] == DQUOTE)
	{
		j++;
		while (s[j] && s[j] != DQUOTE)
			j++;
		if (s[j] == DQUOTE)
			j++;
	}
	else
	{
		j++;
		while (s[j] && s[j] != SQUOTE)
			j++;
		if (s[j] == SQUOTE)
			j++;
	}
	return (j);
}

/*static int	ft_ptr_len(char const *p)
{
	int	i;

	i = 0;
	if (p[i] == DQUOTE)
	{
		i++;
		while (p[i] != DQUOTE)
			i++;
		i++;
		while (p[i] && p[i] != KSPACE)
			i++;
	}
	else if (p[i] == SQUOTE)
	{
		i++;
		while (p[i] != SQUOTE)
			i++;
		i++;
		while (p[i] && p[i] != KSPACE)
			i++;
	}
	else
		while (p[i] != KSPACE && p[i])
			i++;
	return (i);
}*/

static int	ft_ptr_len(char *p)
{
	int	i;
	int in;

	i = 0;
	in = 0;
	while (p[i])
	{
		if (p[i] && (p[i] == DQUOTE || p[i] == SQUOTE))
			i = ft_upd_j(p, i, 0);

		else
		{
			i = ft_upd_j(p, i, 1);
			break ;
		}
	}
	/*if (p[i] == DQUOTE)
	{
		i++;
		while (p[i] != DQUOTE)
			i++;
		i++;
		while (p[i] && p[i] != KSPACE)
			i++;
	}
	else if (p[i] == SQUOTE)
	{
		i++;
		while (p[i] != SQUOTE)
			i++;
		i++;
		while (p[i] && p[i] != KSPACE)
			i++;
	}
	else
		while (p[i] != KSPACE && p[i])
			i++;*/
	return (i);
}


int	ft_str_count(char *s)
{
	int	str_count;
	int	j;
//	int	in;

//	in = 0;
	str_count = 0;
	j = 0;
	if (*s == '\0')
		return (0);
	while (s[j])
	{
		/*if (s[j] == KSPACE)
		{*/
		while (s[j] && s[j] == KSPACE)
			j++;
		//}
		if (s[j])
			str_count++;
		while (s[j] && s[j] != KSPACE && s[j] != DQUOTE && s[j] != SQUOTE)
			j++;
		if (s[j] && (s[j] == DQUOTE || s[j] == SQUOTE))
			j = ft_upd_j(s, j, 1);
		else
			j = ft_upd_j(s, j, 0);
	}
//	printf("str_count: %i\n", str_count);
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
		p = find_ptr(s, KSPACE);
		res[n] = ft_substr(p, 0, ft_ptr_len(p));
		if (res[n] == NULL)
			return (free_all(res, n));
		n++;
		s = s + (p - s) + ft_ptr_len(p);
	}
	res[n] = NULL;
	return (res);
}
