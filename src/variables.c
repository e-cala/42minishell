/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:38:16 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/26 19:19:37 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"	

static char	*init_dlr(char *s)
{
/*	char	*one;
	char	*two;

	one = NULL;
	two = NULL;
	if (ft_strlen(s) == 1)
		return (s);
	else
	{
		one = malloc(sizeof(char) * 6);
		if (!one)
			return (NULL);
		one = "$HOME";
		two = malloc(sizeof(char) * ft_strlen(s));
		if (!two)
			return (NULL);
		two = ft_substr(s, 1, ft_strlen(s) - 1);
		return (ft_strjoin(one, two));
	}*/
}

static char	*put_val(char *dl, int j, char **val)
{
	size_t	len;
	int		i;

	len = ft_strlen(dl);
	i = 0;
	if (dl[0] == '$')
		val[j] = init_dlr(dl);
/*	else if (spl[len - 1] == '~')
		exp[j] = end_virg(spl);
	else
		exp[j] = mid_virg(spl);*/
	return (val[j]);
}

static char	**nametoval(char **dlr, char **val)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dlr[i])
	{
		if (!has_var(dlr[i]))
		{
			val[j] = malloc (sizeof(char) * (ft_strlen(spl[i]) + 1));
			if (!val[j])
				return (NULL);
			ft_strlcpy(val[j++], drl[i], ft_strlen(dlr[i]) + 1);
		}
		else
		{
			val[j] = put_val(dlr[i], j, val);
			j++;
		}
		i++;
	}
	exp[j] = NULL;
	return (exp);
}

char	**repl_var(char **s)
{
	char	**res;
	int		i;

	res = NULL;
	i = 0;
	if (!need_var(s))
		return (s);
	else
	{
		res = malloc (sizeof(char *) * (len + 1));
		if (!res)
			return (NULL);
		res = nametoval(s, res);
	}
	while (res[i])
		i++;
	if (need_var(res))
		res = repl_var(res, i);
	i = 0;
	while (s[i])
		i++;
	free_all(s, i);
	return (res);
}
