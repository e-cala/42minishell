/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:45:32 by ecabanas          #+#    #+#             */
/*   Updated: 2023/09/23 12:51:44 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

/*      prompt.c        	*/
char	*rl_gets(char *line);
void	loop_prompt(char *line);

/*		trim functions		*/
char	**cmdtrim(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
int		readl_test(void);

/*		subsplit functions	*/
char	**cmdsubsplit(char **s, int len);
int		need_split(char **s);
int		only_sep(char *s);
int		is_sep(char c);
int		splitable(char *s);
int		count_new_ptrs(char **s);
char	*first_spl(char *tr);
char	*last_spl(char *tr, int l);
char	*mid_spl(char *tr);

/*      testfunctions.c        */
void	test(char *line);

/*      builtins.c            */
void    ft_echo(const char *message);
void     ft_pwd();

/*      errors.c            */
void    handle_error(const char *message);






#endif
