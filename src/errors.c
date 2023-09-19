#include "../includes/minishell.h"
#include "../includes/defines.h"
#include "../lib/libft/libft.h"

void    err_message(char *str)
{
    ft_putstr_fd("Error: ", 2);
    ft_putendl_fd(str, 1);
    exit(EXIT_FAILURE);
}