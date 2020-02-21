/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:17 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/21 15:34:27 by fprovolo         ###   ########.fr       */
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
	cmd_swap(stk->a);
	cmd_swap(stk->b);
	return ;
}

void	cmd_rr(t_stk *stk)
{
	stk->a = (stk->a) ? stk->a->next : stk->a;
	stk->b = (stk->b) ? stk->b->next : stk->b;
	return ;
}

void	cmd_rrr(t_stk *stk)
{
	stk->a = (stk->a) ? stk->a->prev : stk->a;
	stk->b = (stk->b) ? stk->b->prev : stk->b;
	return ;
}

void	exec_command(t_stk *stk, char *cmd)
{
	if (ft_strequ(cmd, "sa"))
		cmd_swap(stk->a);
	else if (ft_strequ(cmd, "sb"))
		cmd_swap(stk->b);
	else if (ft_strequ(cmd, "ss"))
		cmd_swap_both(stk);
	else if (ft_strequ(cmd, "pa"))
		push_a(pull_b(stk), stk);
	else if (ft_strequ(cmd, "pb"))
		push_b(pull_a(stk), stk);
	else if (ft_strequ(cmd, "ra"))
		stk->a = (stk->a) ? stk->a->next : stk->a;
	else if (ft_strequ(cmd, "rb"))
		stk->b = (stk->b) ? stk->b->next : stk->b;
	else if (ft_strequ(cmd, "rr"))
		cmd_rr(stk);
	else if (ft_strequ(cmd, "rra"))
		stk->a = (stk->a) ? stk->a->prev : stk->a;
	else if (ft_strequ(cmd, "rrb"))
		stk->b = (stk->b) ? stk->b->prev : stk->b;
	else if (ft_strequ(cmd, "rrr"))
		cmd_rrr(stk);
	else
		terminate(FT_OPER);
	return ;
}
