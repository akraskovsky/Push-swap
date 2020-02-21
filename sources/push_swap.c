/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:48:35 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/21 18:30:23 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stk	*stk;

	if (argc < 2)
		return (0);
	if (!(stk = init_stk()))
		terminate(FT_MEM_ERR);
	parse_arguments(argc, argv, stk);
	ft_printf("\nlen = %d\n", sorted_len(stk->a));
	print_stack(stk);
	return (0);
}
