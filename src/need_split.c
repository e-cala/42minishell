/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:10:36 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/22 20:50:18 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"	

int	only_sep(char *s)
{
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

int	is_sep(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

static int	sep_outq(char **s)
{
	int	i;
	
	printf("sep_outq\n");
	i = 0;
	while (s[i])
	{
		if (out_quotes(s[i]))
			return (1);
		else
			i++;
	}
	return (0);
}

static int	seps_alone(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((!ft_strchr(s[i], '<') && !ft_strchr(s[i], '>')
				&& !ft_strchr(s[i], '|')) || only_sep(s[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

/*checks if the ** rec'd needs to be splitted by checking:
 * 1. If some of the strings included has some separator: <, > OR |
 * 2. If seps are alone in all strings in the **, so would need no split, as they are already splitted
 * 3. If separators are present and not alone we get to the las IF, where we check if the separators are between or outside quotes
 * (only in the 2nd case would need split)
 */
int	need_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strchr(s[i], '<') && !ft_strchr(s[i], '>')
			&& !ft_strchr(s[i], '|'))
			i++;
		else
			break ;
	}
	if (s[i] == NULL)
		return (0);
	if (seps_alone(s))
		return (0);
	if (!sep_outq(s))
		return (0);
	return (1);
}
