/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:12:01 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/21 18:30:45 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		sorted_len(t_stack *start)
{
	t_stack	*ptr;
	size_t	len;
	int		num;

	ptr = start;
	len = 1;
	num = ptr->num;
	while (ptr->next != start)
	{
		if (ptr->next->num > num)
		{
			len++;
			num = ptr->next->num;
		}
		else
			ptr->next->index = 1;
		ptr = ptr->next;
	}
	return (len);
}

/*
t_stack		*longest_sort(t_stack *stk)
{
	size_t	len;
	t_stack	*start;
	t_stack	*ptr;
	t_stack *
	
// check if 2 elements!!!
	len = 0;
	start = stk;
	while (start->next != stk)
	{
		ptr = start
		if (ptr->next->num > ptr->num)
		{
			len++;
			ptr = ptr->next;
		}
		ptr = ptr->next;
	}
}
*/
