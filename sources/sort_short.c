/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:28:38 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/06 17:02:06 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stk *stk)
{
	if (stk->a->num > stk->a->next->num && \
			stk->a->num > stk->a->next->next->num)
		cmd_ra(stk, 1);
	else if (stk->a->next->num > stk->a->num && \
			stk->a->next->num > stk->a->next->next->num)
		cmd_rra(stk, 1);
	if (stk->a->num > stk->a->next->num)
		cmd_sa(stk, 1);
	return ;
}

void	sort_4(t_stk *stk)
{
	if (stk->a->next->num < stk->a->num && \
			stk->a->next->num < stk->a->next->next->num && \
			stk->a->next->num < stk->a->next->next->next->num)
		cmd_ra(stk, 1);
	if (stk->a->next->next->num < stk->a->num && \
			stk->a->next->next->num < stk->a->next->num && \
			stk->a->next->next->num < stk->a->next->next->next->num)
	{
		cmd_ra(stk, 1);
		cmd_ra(stk, 1);
	}
	if (stk->a->prev->num < stk->a->num && \
			stk->a->prev->num < stk->a->next->num && \
			stk->a->prev->num < stk->a->next->next->num)
		cmd_rra(stk, 1);
	cmd_pb(stk, 1);
	sort_3(stk);
	cmd_pa(stk, 1);
	return ;
}

int		min_position(t_stk *stk)
{
	int		i;
	int		min;
	int		shift;
	t_stack	*ptr;

	min = stk->a->num;
	shift = 0;
	ptr = stk->a->next;
	i = 0;
	while (++i < (int)stk->len_a)
	{
		if (ptr->num < min)
		{
			min = ptr->num;
			shift = i;
		}
		ptr = ptr->next;
	}
	return (shift);
}

void	sort_5(t_stk *stk)
{
	int		shift;

	shift = min_position(stk);
	if (shift == 1 || shift == 2)
		cmd_ra(stk, 1);
	if (shift == 2)
		cmd_ra(stk, 1);
	if (shift == 4 || shift == 3)
		cmd_rra(stk, 1);
	if (shift == 3)
		cmd_rra(stk, 1);
	cmd_pb(stk, 1);
	sort_4(stk);
	cmd_pa(stk, 1);
	return ;
}

void	sort_short(t_stk *stk)
{
	if (stk->len_a == 2 && stk->a->num > stk->a->next->num)
		cmd_sa(stk, 1);
	else if (stk->len_a == 3)
		sort_3(stk);
	else if (stk->len_a == 4)
		sort_4(stk);
	else if (stk->len_a == 5)
		sort_5(stk);
	return ;
}
