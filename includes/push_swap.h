/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:57:31 by fprovolo          #+#    #+#             */
/*   Updated: 2020/03/03 16:06:05 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>  // for test !!!
# include "libft.h"
# include "ft_printf.h"

# define FT_MEM_ERR "Memory allocation error"
# define FT_ARG_ERR "Error"
# define FT_OPER "Error"

typedef struct 			s_stack
{
	int					num;
	int					index;
	struct s_stack 		*next;
	struct s_stack		*prev;
}						t_stack;

typedef struct 			s_stk
{
	t_stack				*a;
	t_stack				*b;
	size_t				len_a;
	size_t				len_b;
	int					visual;
}						t_stk;

typedef	struct 			s_shift
{
	size_t				a;
	size_t				b;
}						t_shift;

typedef struct			s_cmd
{
	char				*cmd;
	struct s_commands	*next;
	struct s_commands	*prev;
}						t_cmd;

int     	main(int argc, char **argv);
int			parse_arguments(int argc, char **argv, t_stk *stk);
void		terminate(t_stk *stk, char *message);
t_stk		*init_stk();
void		print_stack(t_stk *stk);
void		run_commands(t_stk *stk);
void		exec_command(t_stk *stk, char *cmd);
void		push_a(t_stack *new, t_stk *stk);
void		push_b(t_stack *new, t_stk *stk);
t_stack		*pull_a(t_stk *stk);
t_stack		*pull_b(t_stk *stk);
void		cmd_sa(t_stk *stk, int wr);
void		cmd_sb(t_stk *stk, int wr);
void		cmd_ss(t_stk *stk, int wr);
void		cmd_pa(t_stk *stk, int wr);
void		cmd_pb(t_stk *stk, int wr);
void		cmd_ra(t_stk *stk, int wr);
void		cmd_rb(t_stk *stk, int wr);
void		cmd_rr(t_stk *stk, int wr);
void		cmd_rra(t_stk *stk, int wr);
void		cmd_rrb(t_stk *stk, int wr);
void		cmd_rrr(t_stk *stk, int wr);
int			check_sort(t_stk *stk);
size_t		sorted_len(t_stack *start);
t_stack		*longest_sorted(t_stack *stk);
void		mark_to_push(t_stack *start);
void		trim_nonsorted(t_stk *stk);
void		sort_short(t_stk *stk);
void		sort_main(t_stk *stk);
void		sort_3(t_stk *stk);
void		sort_4(t_stk *stk);
void		sort_5(t_stk *stk);
size_t		find_match(t_stk *stk, int num);
size_t		calc_commands(t_stk *stk, size_t shift_a, size_t shift_b);
void		move_up_up(t_stk *stk, t_shift shift);
void		move_down_down(t_stk *stk, t_shift shift);
void		move_down_up(t_stk *stk, t_shift shift);
void		move_up_down(t_stk *stk, t_shift shift);
void		stk_norm(t_stk *stk);
void		free_stack(t_stack *stack);
void		free_stk(t_stk *stk);

#endif
