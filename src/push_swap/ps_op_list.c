/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:18:24 by maliew            #+#    #+#             */
/*   Updated: 2022/08/10 21:03:40 by maliew           ###   ########.fr       */
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
		ft_printf("p");
	else if (move & SX)
		ft_printf("s");
	else if (move & RX)
		ft_printf("r");
	else if (move & RRX)
		ft_printf("rr");
	if (move & XA && move & XB && move & SX)
		ft_printf("s");
	else if (move & XA && move & XB && (move & RX || move & RRX))
		ft_printf("r");
	else if (move & XA)
		ft_printf("a");
	else
		ft_printf("b");
	ft_printf("\n");
}
