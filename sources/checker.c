/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:48:35 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/21 16:04:05 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_commands(t_stk *stk)
{
	char	*cmd;
	int		ret;

	while ((ret = get_next_line(0, &cmd)) > 0)
	{
		exec_command(stk, cmd);
		free(cmd);
		print_stack(stk);
	}
	return ;
}

int		check_sort(t_stk *stk)
{
	t_stack	*ptr;

	if (stk->b)
		return (0);
	ptr = stk->a->next;
	while (ptr != stk->a)
	{
		if (ptr->num < ptr->prev->num)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_stk	*stk;

	if (argc < 2)
		return (0);
	if (!(stk = init_stk()))
		terminate(FT_MEM_ERR);
	parse_arguments(argc, argv, stk);
	run_commands(stk);
	ft_putendl((check_sort(stk)) ? "\x1B[32mOK" : "\x1B[31mKO");
	return (0);
}
