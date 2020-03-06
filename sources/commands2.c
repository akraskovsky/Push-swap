/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:10:33 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/06 16:45:16 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_rra(t_stk *stk, int wr)
{
	stk->a = (stk->a) ? stk->a->prev : stk->a;
	if (wr)
		write(1, "rra\n", 4);
	return ;
}

void	cmd_rrb(t_stk *stk, int wr)
{
	stk->b = (stk->b) ? stk->b->prev : stk->b;
	if (wr)
		write(1, "rrb\n", 4);
	return ;
}

void	cmd_rrr(t_stk *stk, int wr)
{
	stk->a = (stk->a) ? stk->a->prev : stk->a;
	stk->b = (stk->b) ? stk->b->prev : stk->b;
	if (wr)
		write(1, "rrr\n", 4);
	return ;
}

void	cmd_pa(t_stk *stk, int wr)
{
	push_a(pull_b(stk), stk);
	if (wr)
		write(1, "pa\n", 3);
	return ;
}

void	cmd_pb(t_stk *stk, int wr)
{
	push_b(pull_a(stk), stk);
	if (wr)
		write(1, "pb\n", 3);
	return ;
}
