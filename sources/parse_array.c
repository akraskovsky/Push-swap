/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:12:15 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/19 16:17:32 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		add_to_end_a(int num, t_stk *stk)
{
	t_stack		*new;
	t_stack		*last;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		terminate(FT_MEM_ERR);
	new->num = num;
	new->index = 0;
	if (stk->a == NULL)
	{
		new->next = new;
		new->prev = new;
		stk->a = new;
	}
	else
	{
		last = stk->a->prev;
		last->next = new;
		new->prev = last;
		new->next = stk->a;
		stk->a->prev = new;
	}
	(stk->len)++;
	return ;
}

static char		*parse_word(char *str, t_stk *stk)
{
	int			sign;
	long long	num;

	num = 0;
	sign = (*str == '-') ? -1 : 1;
	if ((*str == '-' || *str == '+') && ft_isdigit(str[1]))
		str++;
	while (*str != '\0' && !ft_isspace(*str))
	{
		if (!ft_isdigit(*str))
			terminate(FT_ARG_ERR);
		num = num * 10 + (*str - '0');
		if (num - 1 > __INT_MAX__)
			terminate(FT_ARG_ERR);
		str++;
	}
	num *= sign;
	if (num > __INT_MAX__ || num < -__INT_MAX__ - 1)
		terminate(FT_ARG_ERR);
	add_to_end_a((int)num, stk);
	return (str);
}

int     parse_array(int argc, char **argv, t_stk *stk)
{
	int		i;
	int		found;
	char	*ptr;
	
	i = 1;
	while (i < argc)
	{
		ptr = argv[i];
		found = 0;
		while (*ptr != '\0')
		{
			while (ft_isspace(*ptr))
				ptr++;
			if (*ptr != '\0')
			{
				found = 1;
				ptr = parse_word(ptr, stk);
			}
		}
		if (!found)
			terminate(FT_ARG_ERR);
		i++;
	}
	print_stack(stk);
	return (0);
}

/*
int     parse_array(int argc, char **argv)
{
	char	**words;
	int		i;
	t_stk	*stk;
	
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
			parse_word(argv[i++], stk);
		}
	}
	print_stack(stk);
	return (0);
}
*/
