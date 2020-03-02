/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:31:04 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/02 18:32:49 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		find_match(t_stk *stk, int num)
{
	size_t		shift_a;
	t_stack		*ptr;

	shift_a = 0;
	ptr = stk->a;
	while (!((ptr->prev->num < num && num < ptr->num) || \
			(ptr->prev->num > ptr->num && \
			(num > ptr->prev->num || num < ptr->num))))
	{
//		ft_printf("num=%d ptr->num=%d shift_a=%d\n", num, ptr->num, shift_a);
		ptr = ptr->next;
		shift_a++;
	}
	return (shift_a);
}

size_t		calc_commands(t_stk *stk, size_t shift_a, size_t shift_b)
{
	size_t		count;

	count = ft_min(ft_max(shift_a, shift_b), \
			ft_max(stk->len_a - shift_a, stk->len_b - shift_b));
	count = ft_min(count, (stk->len_a - shift_a) + shift_b);
	count = ft_min(count, (stk->len_b - shift_b) + shift_a);
	return (count);
}

void		push_to_a(t_stk *stk, t_shift shift)
{
	if (ft_max(shift.a, shift.b) <= ft_max(stk->len_a - shift.a, stk->len_b - shift.b) &&
			ft_max(shift.a, shift.b) <= ft_min(stk->len_a - shift.a + shift.b, shift.a + stk->len_b - shift.b))
		move_up_up(stk, shift);
	else if (ft_max(stk->len_a - shift.a, stk->len_b - shift.b) <= \
			ft_min(stk->len_a - shift.a + shift.b, shift.a + stk->len_b - shift.b))
		move_down_down(stk, shift);
	else if (stk->len_a - shift.a + shift.b <= shift.a + stk->len_b - shift.b)
		move_down_up(stk, shift);
	else
		move_up_down(stk, shift);
	return ;
}

t_shift		best_to_return(t_stk *stk)
{
	size_t		shift_b;
	t_shift		best;
	size_t		count;
	size_t		min_count;
	t_stack		*ptr;	

	min_count = calc_commands(stk, find_match(stk, stk->b->num), 0);
	best.b = 0;
	best.a = find_match(stk, stk->b->num);
	shift_b = 1;
	ptr = stk->b->next;
	while (shift_b < stk->len_b)
	{
		if ((count = calc_commands(stk, find_match(stk, ptr->num), shift_b)) \
				< min_count)
		{
			min_count = count;
			best.b = shift_b;
			best.a = find_match(stk, ptr->num);
		}
//		ft_printf("num=%d shift_a=%d, shift_b=%d, count=%d\n", ptr->num, find_match(stk, ptr->num), shift_b, count);
		ptr = ptr->next;
		shift_b++;
	}
	return (best);
}

void		sort_main(t_stk *stk)
{
	t_shift	shift;

	trim_nonsorted(stk);
//	print_stack(stk);
	while (stk->b)
	{
		shift = best_to_return(stk);
		push_to_a(stk, shift);
//		print_stack(stk);
	}
	stk_norm(stk);
	return ;
}
