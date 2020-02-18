/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:44:15 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/18 18:19:33 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminate(char *message)
{
	ft_putendl(message);
	exit(1);
}

void	print_stack(t_stk *stk)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	ft_printf("%-26s%-26s\n", "Stack A:", "Stack B:");
	ft_printf("%-26s%-26s\n", "--------", "--------");
	ptr_a = stk->a;
	ptr_b = stk->b;
	if (stk->a)
	{
		ft_printf("%-4d%-22d", stk->a->index, stk->a->num);
		ptr_a = stk->a->next;
	}
	else
		ft_printf("%26s", " ");
	if (stk->b)
	{
		ft_printf("%-4d%-22d", stk->b->index, stk->b->num);
		ptr_b = stk->b->next;
	}
	else
		ft_printf("%26s", " ");
	ft_printf("\n");
	while (ptr_a != stk->a || ptr_b != stk->b)
	{
		if (ptr_a != stk->a)
		{
			ft_printf("%-4d%-22d", ptr_a->index, ptr_a->num);
			ptr_a = ptr_a->next;
		}
		else
			ft_printf("%26s", " ");
		if (ptr_b != stk->b)
		{
			ft_printf("%-4d%-22d", ptr_b->index, ptr_b->num);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%26s", " ");
		ft_printf("\n");
	}
	return ;
}
