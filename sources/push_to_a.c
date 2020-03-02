/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:27:41 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/02 19:48:47 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_up_up(t_stk *stk, t_shift shift)
{
	size_t	n_rx;
	size_t	n_rr;
	
	if (shift.a > shift.b)
	{
		n_rx = shift.a - shift.b;
		n_rr = shift.b;
		while (n_rx--)
			cmd_ra(stk, 1);
		while (n_rr--)
			cmd_rr(stk, 1);
	}
	else
	{
		n_rx = shift.b - shift.a;
		n_rr = shift.a;
		while (n_rx--)
			cmd_rb(stk, 1);
		while (n_rr--)
			cmd_rr(stk, 1);
	}
	cmd_pa(stk, 1);
	return ;
}

void	move_down_down(t_stk *stk, t_shift shift)
{
	size_t	n_rrx;
	size_t	n_rrr;
	
	if (stk->len_a - shift.a > stk->len_b - shift.b)
	{
		n_rrx = (stk->len_a - shift.a) - (stk->len_b - shift.b);
		n_rrr = stk->len_b - shift.b;
		while (n_rrx--)
			cmd_rra(stk, 1);
		while (n_rrr--)
			cmd_rrr(stk, 1);
	}
	else
	{
		n_rrx = (stk->len_b - shift.b) - (stk->len_a - shift.a);
		n_rrr = stk->len_a - shift.a;
		while (n_rrx--)
			cmd_rrb(stk, 1);
		while (n_rrr--)
			cmd_rrr(stk, 1);
	}
	cmd_pa(stk, 1);
	return ;
}

void	move_down_up(t_stk *stk, t_shift shift)
{
	size_t	n_rra;
	size_t	n_rb;

	n_rra = stk->len_a - shift.a;
	n_rb = shift.b;
	while (n_rra--)
		cmd_rra(stk, 1);
	while (n_rb--)
		cmd_rb(stk, 1);
	cmd_pa(stk, 1);
	return ;
}

void	move_up_down(t_stk *stk, t_shift shift)
{
	size_t	n_ra;
	size_t	n_rrb;

	n_ra = shift.a;
	n_rrb = stk->len_b - shift.b;
	while (n_ra--)
		cmd_ra(stk, 1);
	while (n_rrb--)
		cmd_rrb(stk, 1);
	cmd_pa(stk, 1);
	return ;
}

void	stk_norm(t_stk *stk)
{
	size_t	shift;
	size_t	n_rra;
	
	t_stack	*ptr;
	if (!(stk->a->num < stk->a->next->num && stk->a->num < stk->a->prev->num))
	{
		ptr = stk->a->next;
		shift = 1;
		while (!(ptr->num < ptr->prev->num && ptr->num < ptr->next->num))
		{
			ptr = ptr->next;
			shift++;
		}
		if (stk->len_a - shift < shift)
		{
			n_rra = stk->len_a - shift;
			while (n_rra--)
				cmd_rra(stk, 1);
		}
		else
			while (shift--)
				cmd_ra(stk, 1);
	}
	return ;
}
