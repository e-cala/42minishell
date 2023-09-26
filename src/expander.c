/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:05:20 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/26 13:02:17 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"	

static char	*virgtohome(char *spl, int j, char **exp)
{
	size_t	len;
	int		i;

	len = ft_strlen(spl);
	i = 0;
	if (exp[0] == '~')
	{
		exp[j++] = ini_exp(spl);




		/////
		//
		//
		//
		//
		//
		//
		if (ft_strlen(spl[j - 1]) == 1)
			spl[j++] = ft_substr(t, 1, len);
		else
			spl[j++] = ft_substr(t, 2, len - 1);
	}
	else if (is_sep(t[len - 1]))
	{
		spl[j++] = last_spl(t, len);
		if (ft_strlen(spl[j - 1]) == len - 1)
			spl[j++] = ft_substr(t, len - 1, 1);
		else
			spl[j++] = ft_substr(t, len - 2, 2);
	}
	else
		fill_mid_two(t, j, spl, len);
	return ;
}

static char	**spltoexp(char **spl, char **exp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (spl[i])
	{
		if (!expandable(spl[i]))
		{
			exp[j] = malloc (sizeof(char) * (ft_strlen(spl[i]) + 1));
			if (!exp[j])
				return (NULL);
			ft_strlcpy(exp[j++], spl[i], ft_strlen(spl[i]) + 1);
		}
		else
		{
			exp[j] = virgtohome(spl[i], j, exp);
			j++;
		}
		i++;
	}
	spl[j] = NULL;
	return (spl);
}

char	**cmdexpand(char **s, int len)
{
	char	**res;
	int		i;

	res = NULL;
	i = 0;
	if (!need_expand(s))
		return (s);
	else
	{
		res = malloc (sizeof(char *) * (len + 1));
		if (!res)
			return (NULL);
		res = spltoexp(s, res);
	}
	while (res[i])
		i++;
	res = cmdexpand(res, i);
	i = 0;
	while (s[i])
		i++;
	free_all(s, i);
	return (res);
}

