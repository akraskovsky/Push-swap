/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:17 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/20 18:21:07 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_swap(t_stack *stk)
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

void	cmd_swap_both(t_stk *stk)
{
	swap(stk->a);
	swap(stk->b);
	return ;
}

void	cmd_push_a(t_stk *stk)
{
	t_stack		*tmp;

	if (source)
	{
		tmp = source;
		if (source->next == source)
			;
	}
}
