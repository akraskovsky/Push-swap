/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:17 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/26 14:58:49 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_ra(t_stk *stk, int wr)
{
	stk->a = (stk->a) ? stk->a->next : stk->a;
	if (wr)
		write(1, "ra\n", 3);
	return ;
}

void	cmd_rb(t_stk *stk, int wr)
{
	stk->b = (stk->b) ? stk->b->next : stk->b;
	if (wr)
		write(1, "rb\n", 3);
	return ;
}

void	cmd_rr(t_stk *stk, int wr)
{
	stk->a = (stk->a) ? stk->a->next : stk->a;
	stk->b = (stk->b) ? stk->b->next : stk->b;
	if (wr)
		write(1, "rr\n", 3);
	return ;
}
