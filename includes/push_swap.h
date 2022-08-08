/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:44:39 by maliew            #+#    #+#             */
/*   Updated: 2022/08/08 21:33:03 by maliew           ###   ########.fr       */
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

void	ps_quick_sort(t_list *first, t_list *last);
t_list	*ps_get_stack(int argc, char **argv);
void	ps_operate(t_ps_list **ps_list, int move);

/* ps_quicksort_stack.c */
void	ps_quicksort_stack_100(t_ps_list **ps_list);
void	ps_quicksort_stack(t_ps_list **ps_list);

/* ps_quicksort_stack_utils.c */
int		ps_round(float f);
void	ps_insert_sort_ba(t_ps_list **ps_list, float min, float max);
void	ps_push_stack_a(t_ps_list **ps_list, float min, float max);
void	ps_split_stack_ab(t_ps_list **ps_list, float min, float max);

/* ps_insertsort_stack.c */
void	ps_push_stack_b(t_ps_list **ps_list, float min, float max);
void	ps_insertsort_stack_100(t_ps_list **ps_list);

/* ps_index_stack.c */
void	ps_index_stack(t_list **stack);

/* ps_list_utils.c */
void	ps_free_content(void *content);
void	*ps_return_content(void *content);
int		ps_lst_index(t_list *stack, float content);
int		ps_lst_hasrange(t_list *stack, float min, float max);
int		ps_lst_issorted(t_list *stack);

t_list	*ps_lst_get(t_list *list, int index);
int		ps_lst_min(t_list *list);
int		ps_lst_max(t_list *list);
int		ps_lst_value(t_list *list, int index);

/* ps_op_list.c */
void	ps_oplst_add(t_list **op, int move);
void	ps_oplst_print(void *content);

void	ps_op_optimizer(t_list **op);

/* temp */
int		ps_count_req_moves(t_ps_list *ps_list, int num);

#endif