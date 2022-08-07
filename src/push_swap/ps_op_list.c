/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:18:24 by maliew            #+#    #+#             */
/*   Updated: 2022/08/07 13:46:44 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_oplst_add(t_list **op, int move)
{
	int	*ptr;

	ptr = (int *)malloc(sizeof(int));
	*ptr = move;
	ft_lstadd_back(op, ft_lstnew(ptr));
}

void	ps_oplst_print(void *content)
{
	int	move;

	move = *((int *)(content));
	if (move & PX)
		write(1, "p", 1);
	else if (move & SX)
		write(1, "s", 1);
	else if (move & RX)
		write(1, "r", 1);
	else if (move & RRX)
		write(1, "rr", 2);
	if (move & XA && move & XB && move & SX)
		write(1, "s", 1);
	else if (move & XA && move & XB && (move & RX || move & RRX))
		write(1, "r", 1);
	else if (move & XA)
		write(1, "a", 1);
	else
		write(1, "b", 1);
	write(1, " ", 1);
}
