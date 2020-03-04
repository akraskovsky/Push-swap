/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:48:35 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/04 17:30:25 by fprovolo         ###   ########.fr       */
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
	if (ft_strequ(argv[1], "-v"))
	{
		stk->visual = 1;
		argv++;
		argc--;
	}
	parse_arguments(argc, argv, stk);
	run_commands(stk);
	ft_putendl((check_sort(stk)) ? "\x1B[32mOK" : "\x1B[31mKO");
	free_stk(stk);
	return (0);
}
