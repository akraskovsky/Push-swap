/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:17 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/25 18:12:38 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_swap(t_stack *stk, int write)
{
	int	num;
	int	index;
	
	if (stk && stk->next != stk)
	{
		num = stk->num;
		index = stk->index;
		stk->num = stk->next->num;
		stk->index = stk->next->index;
		stk->next->num = num;
		stk->next->index = index;
	}
}

void	cmd_ss(t_stk *stk, int write)
{
	cmd_swap(stk->a, write);
	cmd_swap(stk->b, write);
	return ;
}

void	cmd_ra(t_stk *stk, int write)
{
	stk->a = (stk->a) ? stk->a->next : stk->a;
	if (write)
		add_cmd("ra");
	return ;
}

void	cmd_rb(t_stk *stk, int write)
{
	stk->b = (stk->b) ? stk->b->next : stk->b;
	if (write)
		add_cmd("rb");
	return ;
}

void	cmd_rr(t_stk *stk, int write)
{
	stk->a = (stk->a) ? stk->a->next : stk->a;
	stk->b = (stk->b) ? stk->b->next : stk->b;
	if (write)
		add_cmd("rr");
	return ;
}
