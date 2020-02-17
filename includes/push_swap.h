/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:57:31 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/17 17:35:29 by fprovolo         ###   ########.fr       */
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

typedef struct 			s_stk
{
	int					dat;
	int					index;
	struct s_stack 		*next;
	struct s_stack		*prev;
}						t_stk;

typedef struct s_stack
{
	t_stk				*a;
	t_stk				*b;
	int					len;
}						t_stack;

typedef struct			s_cmd
{
	char				*cmd;
	struct s_commands	*next;
	struct s_commands	*prev;
}						t_cmd;

int     main(int argc, char **argv);
int     parse_array(int argc, char **argv);
void	parse_word(char *str, t_stack *stk);
void	terminate(char *message);
#endif
