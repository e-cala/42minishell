/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:42:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/23 13:17:00 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

static char	*mid_spl(char *tr)
{
	char	*sp;
	int		i;

	i = 0;
	while (tr[i] && !is_sep(tr[i]))
		i++;
	sp = malloc (sizeof(char) * i + 1);
	if (!sp)
		return (NULL);
	sp = ft_substr(tr, 0, i);
	return (sp);
}

static char	*last_spl(char *tr, int l)
{
	char	*sp;

	if (tr[l - 1] == '|' || (tr[l - 1] != tr[l - 2]))
	{
		sp = malloc (sizeof(char) * l - 1);
		if (!sp)
			return (NULL);
		sp = ft_substr(tr, 0, l - 1);
	}
	else
	{
		sp = malloc (sizeof(char) * l - 2);
		if (!sp)
			return (NULL);
		sp = ft_substr(tr, 0, l - 2);
	}
	return (sp);
}

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

static void	fill_two_spl(char *t, int j, char **spl)
{
	size_t	k;
	size_t	len;

	k = 0;
	len = ft_strlen(t);
	if (is_sep(t[0]))
	{
		spl[j++] = first_spl(t);
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
	
	else
	{
		spl[j++] = mid_spl(t);
		k = ft_strlen(spl[j - 1]);
		spl[j++] = ft_substr(t, k, len - k + 1);
	}
	return ;
}


/*Receives a ** and another newly created to be returned when filled following
 * criteria in cmdsubsplit ft. String by string belonging to trm: checks if it
 * needs to be splitted, 1) if not, copies it to the current position in spl
 * (returned **), 2) otherwise (if yes), checks if the separator by which we
 * have to split the string is: a) at the beginnning, b) at the end OR c) in
 * the middle of the string, and applies the needed fts to fill the next 2 or 3
 * strings depending on the case a, b or c) in split (returned **).*/
static char	**trimtosplit(char **trm, char **spl)
{
	int		i;
	int		j;
//	size_t	len;
//	size_t	k;

	i = 0;
	j = 0;
//	k = 0;
//	len = 0;
	while (trm[i])
	{
		if (!splitable(trm[i]))
		{
			spl[j] = malloc (sizeof(char) * (len + 1));
			if (!spl[j])
				return (NULL);
			ft_strlcpy(spl[j++], trm[i], len + 1);
		}
	/*	else if (is_sep(trm[i][0]))
		{
			spl[j++] = first_spl(trm[i]);
			if (ft_strlen(spl[j - 1]) == 1)
				spl[j++] = ft_substr(trm[i], 1, len);
			else
				spl[j++] = ft_substr(trm[i], 2, len - 1);
		}
		else if (is_sep(trm[i][len - 1]))
		{
			spl[j++] = last_spl(trm[i], len);
			if (ft_strlen(spl[j - 1]) == len - 1)
				spl[j++] = ft_substr(trm[i], len - 1, 1);
			else
				spl[j++] = ft_substr(trm[i], len - 2, 2);
		}
		else
		{
			spl[j++] = mid_spl(trm[i]);
			k = ft_strlen(spl[j - 1]);
			spl[j++] = ft_substr(trm[i], k, len - k + 1);
		}*/
		i++;
	}
	spl[j] = NULL;
	return (spl);
}

/*Creates a new char ** splitting the received one according to the separators
 * it includes, i.e. '>', '<', '|', '>>' and '<<', ONLY if outside quotes, and
 * leaves them alone as a separated char * in the char ** returned.
 * FIRST IF: In case the received char** doesn't need splitting, it returns the
 * same ** rec'd*/
char	**cmdsubsplit(char **s, int len)
{
	char	**res;
	int		i;

	res = NULL;
	i = 0;
	if (!need_split(s))
		return (s);
	else
	{
		res = malloc (sizeof(char *) * (count_new_ptrs(s) + len + 1));
		if (!res)
			return (NULL);
		res = trimtosplit(s, res);
	}
	while (res[i])
		i++;
	res = cmdsubsplit(res, i);
	return (res);
}
