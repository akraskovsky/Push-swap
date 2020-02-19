/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:44:15 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/19 16:34:15 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminate(char *message)
{
	ft_putendl(message);
	exit(1);
}

t_stk	*init_stk()
{
	t_stk	*stk;

	if (!(stk = (t_stk *)malloc(sizeof(t_stk))))
		return (NULL);
	stk->a = NULL;
	stk->b = NULL;
	stk->len = 0;
	return (stk);
}

void	print_stack(t_stk *stk)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

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
	return ;
}
