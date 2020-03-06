/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:08:24 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/06 17:00:33 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_header(t_stk *stk)
{
	write(1, "\033[0d\033[2J", 8);
	ft_printf("\nStack A (%3zu)    Stack B (%3zu)\n", stk->len_a, stk->len_b);
	ft_printf("-------------    -------------\n");
}

static void		print_all(t_stk *stk, t_stack *ptr_a, t_stack *ptr_b)
{
	while (ptr_a != stk->a || ptr_b != stk->b)
	{
		if (ptr_a != stk->a)
		{
			ft_printf("%13d", ptr_a->num);
			ptr_a = ptr_a->next;
		}
		else
			ft_printf("%13s", " ");
		if (ptr_b != stk->b)
		{
			ft_printf("%17d", ptr_b->num, ptr_b->index);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%17s", " ");
		ft_printf("\n");
	}
	return ;
}

void			print_stack(t_stk *stk)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	print_header(stk);
	ptr_a = stk->a;
	ptr_b = stk->b;
	if (stk->a)
	{
		ft_printf("%13d", stk->a->num);
		ptr_a = stk->a->next;
	}
	else
		ft_printf("%13s", " ");
	if (stk->b)
	{
		ft_printf("%17d", stk->b->num);
		ptr_b = stk->b->next;
	}
	else
		ft_printf("%17s", " ");
	ft_printf("\n");
	print_all(stk, ptr_a, ptr_b);
	usleep(100000);
	return ;
}
