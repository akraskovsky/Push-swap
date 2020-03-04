/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:08:24 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/04 16:09:15 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stk *stk)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	if (!stk)
		return ;
	ft_printf("\n%16s%26s\n", "Stack A:", "Stack B:");
	ft_printf("%16s%26s\n", "--------", "--------");
	ptr_a = stk->a;
	ptr_b = stk->b;
	if (stk->a)
	{
		ft_printf("%12d%4d", stk->a->num, stk->a->index);
		ptr_a = stk->a->next;
	}
	else
		ft_printf("%16s", " ");
	if (stk->b)
	{
		ft_printf("%22d%4d", stk->b->num, stk->b->index);
		ptr_b = stk->b->next;
	}
	else
		ft_printf("%26s", " ");
	ft_printf("\n");
	while (ptr_a != stk->a || ptr_b != stk->b)
	{
		if (ptr_a != stk->a)
		{
			ft_printf("%12d%4d", ptr_a->num, ptr_a->index);
			ptr_a = ptr_a->next;
		}
		else
			ft_printf("%16s", " ");
		if (ptr_b != stk->b)
		{
			ft_printf("%22d%4d", ptr_b->num, ptr_b->index);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%26s", " ");
		ft_printf("\n");
	}
	ft_printf("length A: %d,                length B: %d\n\n", stk->len_a, stk->len_b);
	return ;
}
