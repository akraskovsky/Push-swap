/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:48:35 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/26 17:30:38 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_command(t_stk *stk, char *cmd)
{
	if (ft_strequ(cmd, "sa"))
		cmd_sa(stk, 0);
	else if (ft_strequ(cmd, "sb"))
		cmd_sb(stk, 0);
	else if (ft_strequ(cmd, "ss"))
		cmd_ss(stk, 0);
	else if (ft_strequ(cmd, "pa"))
		cmd_pa(stk, 0);
	else if (ft_strequ(cmd, "pb"))
		cmd_pb(stk, 0);
	else if (ft_strequ(cmd, "ra"))
		cmd_ra(stk, 0);
	else if (ft_strequ(cmd, "rb"))
		cmd_rb(stk, 0);
	else if (ft_strequ(cmd, "rr"))
		cmd_rr(stk, 0);
	else if (ft_strequ(cmd, "rra"))
		cmd_rra(stk, 0);
	else if (ft_strequ(cmd, "rrb"))
		cmd_rrb(stk, 0);
	else if (ft_strequ(cmd, "rrr"))
		cmd_rrr(stk, 0);
	else
		terminate(FT_OPER);
	return ;
}

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
