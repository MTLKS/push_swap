/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:44:39 by maliew            #+#    #+#             */
/*   Updated: 2022/08/05 19:23:33 by maliew           ###   ########.fr       */
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

void	ps_sort_stack(t_list **stack_a);
void	ps_quick_sort(t_list *first, t_list *last);
t_list	*ps_get_stack(int argc, char **argv);
void	ps_operate(t_list **stack_a, t_list **stack_b, int operator);

void	ps_index_stack(t_list **stack);

void	ps_free_content(void *content);
void	ps_print_stack(void *content);

#endif