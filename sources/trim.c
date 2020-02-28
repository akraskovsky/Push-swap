/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:12:01 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/28 18:54:10 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_sort(t_stk *stk)
{
	t_stack	*ptr;

	if (stk->b)
		return (0);
	ptr = stk->a->next;
	while (ptr != stk->a)
	{
		if (ptr->num < ptr->prev->num)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

size_t		sorted_len(t_stack *start)
{
	t_stack	*ptr;
	size_t	len;
	int		num;

	num = start->num;
	len = 1;
	ptr = start->next;
	while (ptr != start)
	{
		if (ptr->next != start && ptr->next->num > num && ptr->next->num < ptr->num)
		{
			num = ptr->num;
			ptr = ptr->next;
			len += 2;
		}
		else if (ptr->num > num)
		{
			len++;
			num = ptr->num;
		}
		ptr = ptr->next;
	}
	return (len);
}

t_stack		*longest_sorted(t_stack *stk)
{
	t_stack	*ptr;
	t_stack	*start;
	size_t	len;
	size_t	l;

	ptr = stk;
	start = stk;
	len = 1;
	while (ptr->next != stk)
	{
		if ((l = sorted_len(ptr)) > len)
		{
			len = l;
			start = ptr;
		}
		ptr = ptr->next;
	}
	if ((l = sorted_len(ptr)) > len)
	{
		len = l;
		start = ptr;
	}
	return (start);
}

void		mark_to_push(t_stack *start)
{
	t_stack	*ptr;
	int		num;

	num = start->num;
	ptr = start->next;
	while (ptr != start)
	{
		if (ptr->next != start && ptr->next->num > num && ptr->next->num < ptr->num)
		{
			ptr->index = 2;
			num = ptr->num;
			ptr = ptr->next;
		}
		else if (ptr->num > num)
			num = ptr->num;
		else
			ptr->index = 1;
		ptr = ptr->next;
	}
	return ;
}

void		trim_nonsorted(t_stk *stk)
{
	int		count;

	mark_to_push(longest_sorted(stk->a));
	count = stk->len_a;
	while (count > 0)
	{
		if (stk->a->index == 2)
		{
			cmd_sa(stk, 1);
			cmd_ra(stk, 1);
			cmd_ra(stk, 1);
			count -= 2;
		}
		else if (stk->a->index == 1)
		{
			cmd_pb(stk, 1);
			count--;
		}
		else
		{
			cmd_ra(stk, 1);
			count--;
		}
	}
	return ;
}
