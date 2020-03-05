/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:46:49 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/05 14:36:42 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_line(t_stk *stk, int start_x, int start_y, int len, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < stk->step - 1)
		{
			mlx_pixel_put(stk->mlx, stk->win, start_x + i, start_y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_header(t_stk *stk)
{
	char	*str;

	mlx_string_put(stk->mlx, stk->win, SPACE_X, SPACE_Y - 35, \
			COL_TXT, "Stack A:");
	str = ft_itoa((int)stk->len_a);
	mlx_string_put(stk->mlx, stk->win, SPACE_X + 90, SPACE_Y - 35, \
			COL_TXT, str);
	free(str);
	mlx_string_put(stk->mlx, stk->win, SPACE_X * 2 + STK_W, SPACE_Y - 35, \
			COL_TXT, "Stack B:");
	str = ft_itoa((int)stk->len_b);
	mlx_string_put(stk->mlx, stk->win, SPACE_X * 2 + STK_W + 90, SPACE_Y - 35, \
			COL_TXT, str);
	free(str);

}

int		draw_stacks(t_stk *stk)
{
	size_t	i;
	t_stack	*ptr;

	mlx_clear_window(stk->mlx, stk->win);
	draw_header(stk);
	i = 0;
	ptr = stk->a;
	while (i < stk->len_a)
	{
		draw_line(stk, SPACE_X, SPACE_Y + stk->step * i, ptr->num, COL_BARS);
		ptr = ptr->next;
		i++;
	}
	i = 0;
	ptr = stk->b;
	while (i < stk->len_b)
	{
		draw_line(stk, SPACE_X + STK_W + SPACE_X, SPACE_Y + stk->step * i, \
				ptr->num, COL_BARS);
		ptr = ptr->next;
		i++;
	}
	return (0);
}
