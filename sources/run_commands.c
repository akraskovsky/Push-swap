/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:29:18 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/06 17:58:54 by fprovolo         ###   ########.fr       */
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
	return ;
}

void	draw_result(t_stk *stk)
{
	char	*str;

	str = ft_itoa((int)stk->len_a);
	mlx_string_put(stk->mlx, stk->win, 100 + STK_W, SPACE_Y + 300,\
		COL_TXT, str);
	free(str);
	mlx_string_put(stk->mlx, stk->win, 100 + STK_W, SPACE_Y + 300,\
		COL_TXT, "    items are sorted");
	mlx_string_put(stk->mlx, stk->win, 100 + STK_W, SPACE_Y + 330,\
		COL_TXT, "in       commands.");
	str = ft_itoa((int)stk->len_cmd);
	mlx_string_put(stk->mlx, stk->win, 100 + STK_W + 30,\
		SPACE_Y + 330, COL_TXT, str);
	free(str);
	mlx_string_put(stk->mlx, stk->win, 100 + STK_W, SPACE_Y + 380,\
		COL_CTA, "Press <ESC> to finish");
	return ;
}

int		key_pressed(int key, t_stk *stk)
{
	char	*cmd;

	if (key == 53)
	{
		mlx_destroy_window(stk->mlx, stk->win);
		ft_finish(stk);
	}
	if (key == 49)
		while (stk->commands)
		{
			cmd = pull_cmd(stk);
			exec_command(stk, cmd);
			free(cmd);
			draw_stacks(stk);
			mlx_do_sync(stk->mlx);
			if (stk->len_a < 15)
				usleep(250000);
		}
	draw_result(stk);
	mlx_do_sync(stk->mlx);
	return (0);
}

void	run_visual(t_stk *stk)
{
	if ((stk->step = STK_H / stk->len_a) < 2)
	{
		ft_printf("Too long array for graphics. Switch to standard mode.\n\n");
		stk->visual = 0;
		return ;
	}
	if (!(stk->mlx = mlx_init()))
		terminate(stk, "Initialization error");
	if (!(stk->win = mlx_new_window(stk->mlx, (int)WIN_X, (int)WIN_Y, \
			"Push-Swap")))
		terminate(stk, "Initialization error");
	calc_scale(stk);
	draw_stacks(stk);
	mlx_string_put(stk->mlx, stk->win, 100 + STK_W, SPACE_Y + 20,\
			COL_CTA, "Press <SPACE> to start sorting");
	mlx_key_hook(stk->win, key_pressed, stk);
	mlx_loop(stk->mlx);
	return ;
}

void	run_commands(t_stk *stk)
{
	char	*cmd;
	int		ret;

	cmd = NULL;
	while ((ret = get_next_line(0, &cmd)) > 0)
	{
		push_cmd(stk, cmd);
		stk->len_cmd++;
	}
	if (cmd)
		free(cmd);
	if (stk->visual == 1 && stk->a)
		run_visual(stk);
	else if (stk->visual == 2)
		while (stk->commands)
		{
			exec_command(stk, pull_cmd(stk));
			print_stack(stk);
		}
	if (stk->visual == 0)
		while (stk->commands)
			exec_command(stk, pull_cmd(stk));
	return ;
}
