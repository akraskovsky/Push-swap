/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:44:15 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/04 16:11:13 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminate(t_stk *stk, char *message)
{
	ft_printf_fd(2, "{RED}%s{OFF}\n", message);
	free_stk(stk);
	exit(1);
}

void	ft_finish(t_stk *stk)
{
	free_stk(stk);
	exit(1);
}

t_stk	*init_stk()
{
	t_stk	*stk;

	if (!(stk = (t_stk *)malloc(sizeof(t_stk))))
		return (NULL);
	stk->a = NULL;
	stk->b = NULL;
	stk->commands = NULL;
	stk->len_a = 0;
	stk->len_b = 0;
	stk->visual = 0;
	stk->mlx = NULL;
	stk->win = NULL;
	return (stk);
}

void	free_stack(t_stack *stack)
{
	t_stack		*tmp;

	while (stack != stack->next)
	{
		tmp = stack;
		stack->prev->next = stack->next;
		stack->next->prev = stack->prev;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
}

void	free_stk(t_stk *stk)
{
	if (stk)
	{
		if (stk->a)
			free_stack(stk->a);
		if (stk->b)
			free_stack(stk->b);
		while (stk->commands)
			pull_cmd(stk);
		free(stk);
	}
}
