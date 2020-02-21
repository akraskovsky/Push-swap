/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_pull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:15:26 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/21 15:19:31 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *new, t_stk *stk)
{
	if (new && stk->a == NULL)
	{
		new->next = new;
		new->prev = new;
		stk->a = new;
	}
	else if (new)
	{
		stk->a->prev->next = new;
		new->prev = stk->a->prev;
		stk->a->prev = new;
		new->next = stk->a;
		stk->a = new;
	}
	return ;
}

void	push_b(t_stack *new, t_stk *stk)
{
	if (new && stk->b == NULL)
	{
		new->next = new;
		new->prev = new;
		stk->b = new;
	}
	else if (new)
	{
		stk->b->prev->next = new;
		new->prev = stk->b->prev;
		stk->b->prev = new;
		new->next = stk->b;
		stk->b = new;
	}
	return ;
}

t_stack	*pull_a(t_stk *stk)
{
	t_stack	*elem;

	if (stk->a == NULL)
		return (NULL);
	elem = stk->a;
	if (stk->a->next == stk->a)
		stk->a = NULL;
	else
	{
		stk->a->prev->next = stk->a->next;
		stk->a->next->prev = stk->a->prev;
		stk->a = stk->a->next;
	}
	return (elem);
}

t_stack	*pull_b(t_stk *stk)
{
	t_stack	*elem;

	if (stk->b == NULL)
		return (NULL);
	elem = stk->b;
	if (stk->b->next == stk->b)
		stk->b = NULL;
	else
	{
		stk->b->prev->next = stk->b->next;
		stk->b->next->prev = stk->b->prev;
		stk->b = stk->b->next;
	}
	return (elem);
}
