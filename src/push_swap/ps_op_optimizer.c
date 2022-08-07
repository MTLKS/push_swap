/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_optimizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:05:16 by maliew            #+#    #+#             */
/*   Updated: 2022/08/07 20:46:02 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_replace_and_delete(t_list *buffer, int move)
{
	t_list	*temp;

	temp = buffer->next;
	*(int *)buffer->content = move;
	buffer->next = buffer->next->next;
	ft_lstdelone(temp, &ps_free_content);
}

void	ps_op_optimizer(t_list **op)
{
	t_list	*buffer;
	int		curr;
	int		next;

	buffer = *op;
	while (buffer && buffer->next)
	{
		curr = *(int *)buffer->content;
		next = *(int *)buffer->next->content;
		if ((curr & next) == SX)
			ps_replace_and_delete(buffer, SS);
		else if ((curr & next) == RX)
			ps_replace_and_delete(buffer, RR);
		else if ((curr & next) == RRX)
			ps_replace_and_delete(buffer, RRR);
		buffer = buffer->next;
	}
}
