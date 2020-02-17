/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:12:15 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/17 17:37:38 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stk()
{
	t_stack	*stk;

	if (!(stk = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stk->a = NULL;
	stk->b = NULL;
	stk->len = 0;
	return (stk);
}

void	parse_word(char *str, t_stack *stk)
{
	printf("parced \'%s\'\n", str);
	stk->len += 1;
	ft_printf("len=%d\n", stk->len);
	return ;
}

int     parse_array(int argc, char **argv)
{
	char	**words;
	int		i;
	t_stack	*stk;
	
	if (!(stk = init_stk()))
		return (0);
	if (argc == 2)
	{
		if (!(words = ft_strsplit(argv[1], ' ')))
			terminate(FT_MEM_ERR);
		i = 0;
		while (words[i])
			parse_word(words[i++], stk);
	}
	else if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			ft_printf("i=%d\n", i);
			parse_word(argv[i++], stk);
		}
	}
	return (0);
}
