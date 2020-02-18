/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:57:31 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/18 18:19:03 by fprovolo         ###   ########.fr       */
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
# define FT_ARG_ERR "Incorrect argument type"

typedef struct 			s_stack
{
	int					num;
	int					index;
	struct s_stack 		*next;
	struct s_stack		*prev;
}						t_stack;

typedef struct s_stk
{
	t_stack				*a;
	t_stack				*b;
	int					len;
}						t_stk;

typedef struct			s_cmd
{
	char				*cmd;
	struct s_commands	*next;
	struct s_commands	*prev;
}						t_cmd;

int     main(int argc, char **argv);
int     parse_array(int argc, char **argv);
//void	parse_word(char *str, t_stk *stk);
void	terminate(char *message);
void	print_stack(t_stk *stk);
#endif
