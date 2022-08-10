/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:44:39 by maliew            #+#    #+#             */
/*   Updated: 2022/08/10 20:59:11 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define PX		0b00000100
# define SX		0b00001000
# define RX		0b00010000
# define RRX	0b00100000
# define XA		0b00000001
# define XB		0b00000010

# define PA		0b00000101
# define PB		0b00000110
# define SA		0b00001001
# define SB		0b00001010
# define SS		0b00001011
# define RA		0b00010001
# define RB		0b00010010
# define RR		0b00010011
# define RRA	0b00100001
# define RRB	0b00100010
# define RRR	0b00100011

typedef struct s_ps_list
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*operations;
}	t_ps_list;

/* ps_stack_utils.c */
t_list	*ps_get_stack(int argc, char **argv);
void	ps_index_stack(t_list **stack);

/* ps_operate.c */
void	ps_operate(t_ps_list **ps_list, int move);

/* ps_sort_stack.c */
void	ps_sort_stack(t_ps_list **ps_list);

/* ps_sort_utils.c */
void	ps_insert_op(t_ps_list **ps_list, int min, int max);
void	ps_push_op(t_ps_list **ps_list, int min, int max);
void	ps_split_op(t_ps_list **ps_list, int min, int max);
void	ps_push_last(t_ps_list **ps_list, int min, int max);

/* ps_list_utils.c */
void	ps_free_content(void *content);
void	*ps_return_content(void *content);
int		ps_lst_index(t_list *stack, int content);
int		ps_lst_hasrange(t_list *stack, int min, int max);
int		ps_lst_issorted(t_list *stack);

/* ps_list_utils2.c */
t_list	*ps_lst_get(t_list *list, int index);
int		ps_lst_min(t_list *list);
int		ps_lst_max(t_list *list);
int		ps_lst_value(t_list *list, int index);
int		ps_lst_indexinrange(t_list *list, int min, int max);

/* ps_list_quicksort.c */
void	ps_list_quicksort(t_list *first, t_list *last);

/* ps_op_list.c */
void	ps_oplst_add(t_list **op, int move);
void	ps_oplst_print(void *content);

/* ps_op_optimizer.c */
void	ps_op_optimizer(t_list **op);

/* ps_range_utils.c */
int		*ps_range_new(int min, int max);
int		ps_range_get(t_list *range, int max);

#endif