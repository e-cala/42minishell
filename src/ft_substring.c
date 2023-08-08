/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:40:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/08/07 21:41:15 by yourLogin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_substring(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);

static char	*ft_strdup(char *s1)
{
	int		len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = malloc((size_t)len + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, (size_t)len + 1);
	return (s2);
}

char	*ft_substring(char *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;
	int		n;

	i = 0;
	if (*s == '\0')
		return (ft_strdup(s));
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	n = (int)len;
	if ((size_t)start + len > ft_strlen(s))
		n = ft_strlen(s) - (size_t)start;
	p = malloc((size_t)n + 1);
	if (p == NULL)
		return (NULL);
	while (i < n)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
