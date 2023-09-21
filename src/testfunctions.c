#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

void	test(char *line)
{
	int i = 0;
	int j = 0;
	char **cmd;

	cmd = cmdtrim(line);
	while (cmd[i])
	{
		printf("%s\n", cmd[i]);
		i++;
	}
	cmdsubsplit(cmdtrim(line), i);
	if (need_split(cmd))
		cmd = cmdsubsplit(cmd, i);
	while (cmd[j])
	{
		printf("%s\n", cmd[j]);
		j++;
	}
}