/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:46:49 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/04 19:56:22 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_visual(t_stk *stk)
{
	if (!(stk->mlx = mlx_init()))
		terminate(stk, "Initialization error");
	if (!(stk->win = mlx_new_window(stk->mlx, WIN_X, WIN_Y,	"Push-Swap")))
		terminate(stk, "Initialization error");
	stk->step = STK_H / stk->len_a;
}

void	draw_line(t_stk *stk, int start_x, int start_y, int len, int height)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < height)
		{
			mlx_pixel_put(stk->mlx, stk->win, start_x + i, start_y + j, COL_BARS);
			j++;
		}
		i++;
	}
}

int		draw_stacks(t_stk *stk)
{
	size_t	i;
	t_stack	*ptr;

	mlx_clear_window(stk->mlx, stk->win);
	mlx_string_put(stk->mlx, stk->win, SPACE_X, SPACE_Y - 35, COL_TXT, "Stack A");
	mlx_string_put(stk->mlx, stk->win, SPACE_X * 2 + STK_W, SPACE_Y - 35, COL_TXT, "Stack B");
	i = 0;
	ptr = stk->a;
	while (i < stk->len_a)
	{
		draw_line(stk, SPACE_X, SPACE_Y + stk->step * i, ptr->num, stk->step - 2);
		ptr = ptr->next;
		i++;
	}
	i = 0;
	ptr = stk->b;
	while (i < stk->len_b)
	{
		draw_line(stk, SPACE_X + STK_W + SPACE_X, SPACE_Y + stk->step * i, ptr->num, stk->step - 2);
		ptr = ptr->next;
		i++;
	}
	return (0);
}

int		start_commands(t_stk *stk)
{
	while (stk->commands)
	{	
		exec_command(stk, pull_cmd(stk));
		usleep(500000);
		ft_printf("Command done\n");
		draw_stacks(stk);
	}
	return (0);
}

int		key_pressed(int key, t_stk *stk)
{
	ft_printf("%d pressed\n", key);
	if (key == 53)
	{
		mlx_destroy_window(stk->mlx, stk->win);
		ft_finish(stk);
	}
/*	if (key == 49)
	{
		while (stk->commands)
		{	
			exec_command(stk, pull_cmd(stk));
			usleep(500000);
			ft_printf("Command done\n");
//			draw_stacks(stk);
		}
		mlx_clear_window(stk->mlx, stk->win);
//		draw_stacks(stk);
	}*/
	return (0);
}
