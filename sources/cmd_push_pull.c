/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push_pull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:29:18 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/06 16:47:40 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_cmd(t_stk *stk, char *cmd)
{
	t_cmd	*new;
	t_cmd	*ptr;

	if (!(ft_strequ(cmd, "sa") || ft_strequ(cmd, "sb") || ft_strequ(cmd, "ss") \
			|| ft_strequ(cmd, "pa") || ft_strequ(cmd, "pb") \
			|| ft_strequ(cmd, "ra") || ft_strequ(cmd, "rb") \
			|| ft_strequ(cmd, "rr") || ft_strequ(cmd, "rra") \
			|| ft_strequ(cmd, "rrb") || ft_strequ(cmd, "rrr")))
		terminate(stk, FT_OPER);
	if (!(new = (t_cmd *)malloc(sizeof(t_cmd))))
		terminate(stk, FT_MEM_ERR);
	new->cmd = cmd;
	new->next = NULL;
	if (!(stk->commands))
		stk->commands = new;
	else
	{
		ptr = stk->commands;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

char	*pull_cmd(t_stk *stk)
{
	char	*cmd;
	t_cmd	*tmp;

	cmd = NULL;
	if (stk->commands)
	{
		cmd = stk->commands->cmd;
		tmp = stk->commands;
		stk->commands = stk->commands->next;
		free(tmp);
	}
	return (cmd);
}
