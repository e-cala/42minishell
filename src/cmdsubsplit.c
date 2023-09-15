/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:42:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/15 20:47:36 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

static char	*first_spl(char *tr)
{
	char	*sp;

	if (tr[0] == '|' || (tr[0] != tr[1]))
	{
		sp = malloc (sizeof(char) + 1);
		if (!sp)
			return (NULL);
		sp = ft_substr(tr, 0, 1);
	}
	else
	{
		sp = malloc (sizeof(char) * 2 + 1);
		if (!sp)
			return (NULL);
		sp = ft_substr(tr, 0, 2);
	}
	return (sp);
}

static char	**trimtosplit(char **trm, char **spl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (trm[i])
	{
		if (trm[i][0] != '<' && trm[i][0] != '>' && trm[i][0] != '|')
		{
			spl[j] = malloc (sizeof(char) * (ft_strlen(trm[i]) + 1));
			if (!spl[j])
				return (NULL);
			ft_strlcpy(spl[j++], trm[i], ft_strlen(trm[i]) + 1);
		}
		else
		{
			spl[j++] = first_spl(trm[i]);
			if (ft_strlen(spl[j - 1]) == 1)
				spl[j++] = ft_substr(trm[i], 1, ft_strlen(trm[i]));
			else
				spl[j++] = ft_substr(trm[i], 2, ft_strlen(trm[i]));
		}
		i++;
	}
	return (spl);
}

static int	count_new_ptrs(char **s)
{
	int	num;
	int	i;
	int	len;

	num = 0;
	i = 0;
	len = 0;
	while (s[i])
	{
		len = ft_strlen(s[i]);
		if ((s[i][0] == '<' || s[i][0] == '>' || s[i][0] == '|') && len > 1)
			num++;
		i++;
	}
	return (num);
}

static int	need_split(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_strlen(s[i]) > 2 && ft_strchr(s[i], '<'))
			return (1);
		else if (ft_strlen(s[i]) > 2 && ft_strchr(s[i], '>'))
			return (1);
		else if (ft_strlen(s[i]) > 1 && ft_strchr(s[i], '|'))
			return (1);
		else if (ft_strlen(s[i]) == 2 && ft_strchr(s[i], '<') && s[i][0] != s[i][1])
			return (1);
		else if (ft_strlen(s[i]) == 2 && ft_strchr(s[i], '>') && s[i][0] != s[i][1])
			return (1);
		i++;
	}
	return (0);
}

char	**cmdsubsplit(char **s, int len)
{
	char	**res;

	res = NULL;
	printf("needs split?: %i\n", need_split(s));
	if (!need_split(s))
		return (s);
	else
	{
		res = malloc (sizeof(char *) * (count_new_ptrs(s) + len + 1)); //NEED TO REDO THIS COUNTING FUNCTION
		//jo crec que podem fer una 1a divisio i dpres iterar per si en queden... (casos de cadenes amb 2 o + separadors)
		if (!res)
			return (NULL);
		res = trimtosplit(s, res);
	}
	return (res);
}
