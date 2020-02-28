/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:31:04 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/28 19:31:34 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_match(t_stk *stk, int num)
{
	int		shift_a;
	t_stack	*ptr;

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

int		calc_commands(t_stk *stk, int shift_a, int shift_b)
{
	int		count;

	count = ft_min(ft_max(shift_a, shift_b), ft_max(stk->len_a - shift_a, stk->len_b - shift_b));
	count = ft_min(count, (stk->len_a - shift_a) + shift_b);
	count = ft_min(count, (stk->len_b - shift_b) + shift_a);
	return (count);
}

void	sort_main(t_stk *stk)
{
	int		shift_b;
	int		count;
	int		min_count;
	t_stack	*ptr;

	trim_nonsorted(stk);
	print_stack(stk);
	min_count = calc_commands(stk, find_match(stk, ptr->num), 0);
	shift_b = 1;
	ptr = stk->b;
	while (shift_b < stk->len_b)
	{
		count = calc_commands(stk, find_match(stk, ptr->num), shift_b);
		ft_printf("num=%d shift_a=%d, shift_b=%d, count=%d\n", ptr->num, find_match(stk, ptr->num), shift_b, count);
		ptr = ptr->next;
		shift_b++;
	}
	return ;
}
