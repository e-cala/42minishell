/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:38:52 by erosas-c          #+#    #+#             */
/*   Updated: 2023/09/19 21:03:46 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/defines.h"
#include <fcntl.h>

/* int main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;
	(void)envp;
	static char *line = NULL;
	loop_prompt(line);
	return(0);
}
 */
#define MAX_PATH_LEN 800
 int main() {
    char cwd[MAX_PATH_LEN];
    ssize_t len;

    int fd = open("/proc/self/fd", 0);
    if (fd < 0)
        handle_error("Failed to open /proc/self/fd");

    len = readlink("/proc/self/fd", cwd, MAX_PATH_LEN - 1);
    if (len < 0)
        handle_error("Failed to read symlink");

    cwd[len] = '\0';  // Null-terminate the string
    printf("Current working directory: %s\n", cwd);

    close(fd);
    return 0;
}