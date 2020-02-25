/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:12:01 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/25 16:20:38 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack	*head;
	size_t	len;
	size_t	l;

	ptr = stk;
	head = stk;
	len = 1;
	while (ptr->next != stk)
	{
		if ((l = sorted_len(ptr)) > len)
		{
			len = l;
			head = ptr;
		}
		ptr = ptr->next;
	}
	return (head);
}

void		mark_to_push(t_stack *head)
{
	t_stack	*ptr;
	int		num;

	num = head->num;
	ptr = head->next;
	while (ptr != head)
	{
		if (ptr->next != head && ptr->next->num > num && ptr->next->num < ptr->num)
		{
			ptr->index = 2;
			num = ptr->num;
			ptr = ptr->next;
		}
		else if (ptr->num > num)
		{
			num = ptr->num;
		}
		ptr = ptr->next;
	}
	return ;
}

void		trim_nonsorted(t_stk *stk)
{
	t_stack	*ptr;

	mark_to_push(longest_sorted(stk->a));
	ptr = stk->a;
	while (ptr->next != stk->a)
	{
		if (ptr->index = 2)
			add_sa()
		{
			len = l;
			head = ptr;
		}
		ft_printf("from %3d len=%zu\n", ptr->num, sorted_len(ptr));
		ptr = ptr->next;
	}
}
