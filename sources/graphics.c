/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:46:49 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/06 16:51:17 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_line(t_stk *stk, int st_x, int st_y, int len)
{
	int		i;
	int		j;

	i = 0;
	while (len > 0 && i <= len)
	{
		j = 0;
		while (j < stk->step - 1)
		{
			mlx_pixel_put(stk->mlx, stk->win, st_x + i, st_y + j, COL_BARS);
			j++;
		}
		i++;
	}
	while (len < 0 && i >= len)
	{
		j = 0;
		while (j < stk->step - 1)
		{
			mlx_pixel_put(stk->mlx, stk->win, st_x + i, st_y + j, COL_NG_BARS);
			j++;
		}
		i--;
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

void	calc_scale(t_stk *stk)
{
	long	range;
	t_stack	*ptr;

	if (!stk->a)
		return ;
	stk->step = STK_H / stk->len_a;
	stk->max_item = stk->a->num;
	stk->min_item = stk->a->num;
	ptr = stk->a->next;
	while (ptr != stk->a)
	{
		if (ptr->num > stk->max_item)
			stk->max_item = ptr->num;
		if (ptr->num < stk->min_item)
			stk->min_item = ptr->num;
		ptr = ptr->next;
	}
	range = (stk->min_item < 0) ? stk->max_item - stk->min_item : stk->max_item;
	stk->scale = (float)STK_W / (float)range;
	if (stk->min_item < 0)
		stk->z_shift = (int)(-stk->min_item * stk->scale);
	return ;
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
		draw_line(stk, SPACE_X + stk->z_shift, SPACE_Y + stk->step * i, \
			(int)(ptr->num * stk->scale));
		ptr = ptr->next;
		i++;
	}
	i = 0;
	ptr = stk->b;
	while (i < stk->len_b)
	{
		draw_line(stk, SPACE_X + STK_W + SPACE_X + stk->z_shift, \
			SPACE_Y + stk->step * i, (int)(ptr->num * stk->scale));
		ptr = ptr->next;
		i++;
	}
	return (0);
}
