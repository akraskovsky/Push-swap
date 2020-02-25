/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:10:33 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/25 18:21:26 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_rra(t_stk *stk, int write)
{
	stk->a = (stk->a) ? stk->a->prev : stk->a;
	if (write)
		add_cmd("rra");
	return ;
}

void	cmd_rrb(t_stk *stk, int write)
{
	stk->b = (stk->b) ? stk->b->prev : stk->b;
	if (write)
		add_cmd("rrb");
	return ;
}

void	cmd_rrr(t_stk *stk, int write)
{
	stk->a = (stk->a) ? stk->a->prev : stk->a;
	stk->b = (stk->b) ? stk->b->prev : stk->b;
	if (write)
		add_cmd("rrr");
	return ;
}

void	cmd_pa(t_stk *stk, int write)
{
	push_a(pull_b(stk), stk);
	if (write)
		add_cmd("pa");
	return ;
}

void	cmd_pb(t_stk *stk, int write)
{
	push_b(pull_a(stk), stk);
	if (write)
		add_cmd("pa");
	return ;
}

