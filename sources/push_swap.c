/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:48:35 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/03 16:22:21 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stk	*stk;

	if (argc < 2)
		return (0);
	if (!(stk = init_stk()))
		terminate(stk, FT_MEM_ERR);
	parse_arguments(argc, argv, stk);
	if (check_sort(stk))
		return (0);
	if (stk->len_a <= 5)
		sort_short(stk);
	else
		sort_main(stk);
	free_stk(stk);
	return (0);
}
