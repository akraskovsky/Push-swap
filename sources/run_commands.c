/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:29:18 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/04 20:21:32 by fprovolo         ###   ########.fr       */
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
		terminate(stk, FT_OPER);
/*	if (stk->visual)
	{
		usleep(500000);
		draw_stacks(stk);
	}*/
	return ;
}

void	run_commands(t_stk *stk)
{
	char	*cmd;
	int		ret;

	while ((ret = get_next_line(0, &cmd)) > 0)
		push_cmd(stk, cmd);
	free(cmd);
	if (stk->visual)
	{
		init_visual(stk);
		draw_stacks(stk);
		while (stk->commands)
		{	
			exec_command(stk, pull_cmd(stk));
			usleep(1000000);
			print_stack(stk);
//			mlx_loop_hook(stk->mlx, draw_stacks, stk);
//			draw_stacks(stk);
		}
//		draw_stacks(stk);

//		start_commands(stk);
//		mlx_loop_hook(stk->mlx, start_commands, stk);
		mlx_key_hook(stk->win, key_pressed, stk);
		mlx_loop(stk->mlx);
	}
	else
		while (stk->commands)	
			exec_command(stk, pull_cmd(stk));
	return ;
}
