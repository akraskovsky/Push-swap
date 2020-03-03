/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:46:49 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/03 20:03:52 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_visual(t_stk *stk)
{
	if (!(stk->mlx = mlx_init()))
		terminate(stk, "Initialization error");
	if (!(stk->win = mlx_new_window(stk->mlx, WIN_X, WIN_Y,	"Push-Swap")))
		terminate(stk, "Initialization error");

}
