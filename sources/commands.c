/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:17 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/26 15:03:39 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_sa(t_stk *stk, int wr)
{
	int	num;
	int	index;
	
	if (stk->a && stk->a->next != stk->a)
	{
		num = stk->a->num;
		index = stk->a->index;
		stk->a->num = stk->a->next->num;
		stk->a->index = stk->a->next->index;
		stk->a->next->num = num;
		stk->a->next->index = index;
	}
	if (wr)
		write(1, "sa\n", 3);
	return ;
}

void	cmd_sb(t_stk *stk, int wr)
{
	int	num;
	int	index;
	
	if (stk->b && stk->b->next != stk->b)
	{
		num = stk->b->num;
		index = stk->b->index;
		stk->b->num = stk->b->next->num;
		stk->b->index = stk->b->next->index;
		stk->b->next->num = num;
		stk->b->next->index = index;
	}
	if (wr)
		write(1, "sb\n", 3);
	return ;
}

void	cmd_ss(t_stk *stk, int wr)
{
	cmd_sa(stk, 0);
	cmd_sb(stk, 0);
	if (wr)
		write(1, "ss\n", 3);
	return ;
}
