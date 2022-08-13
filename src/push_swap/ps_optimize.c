/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:05:16 by maliew            #+#    #+#             */
/*   Updated: 2022/08/13 15:29:18 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_replace_swap_op(t_list *op)
{
	int		a;
	int		b;
	int		c;

	while (op && op->next && op->next->next)
	{
		a = *(int *)op->content;
		b = *(int *)op->next->content;
		c = *(int *)op->next->next->content;
		if ((a == RA && b == PB && c == RRA)
			|| (a == RB && b == PA && c == RRB))
		{
			if (a == RA)
				ps_replace_and_delete2(op, SA);
			else
				ps_replace_and_delete2(op, SB);
		}
		else
			op = op->next;
	}
}

void	ps_merge_op(t_list *op)
{
	int	curr;
	int	next;

	while (op && op->next)
	{
		curr = *(int *)op->content;
		next = *(int *)op->next->content;
		if ((curr & next) == SX)
			ps_replace_and_delete(op, SS);
		else if ((curr & next) == RX)
			ps_replace_and_delete(op, RR);
		else if ((curr & next) == RRX)
			ps_replace_and_delete(op, RRR);
		op = op->next;
	}
}

void	ps_remove_op(t_list **op)
{
	t_list	*buffer;
	t_list	*temp;
	t_list	*temp2;
	int		a;
	int		b;

	buffer = *op;
	while (buffer && buffer->next && buffer->next->next)
	{
		a = *(int *)buffer->next->content;
		b = *(int *)buffer->next->next->content;
		if ((a | b) == (PX | XA | XB))
		{
			temp = buffer->next;
			temp2 = buffer->next->next;
			buffer->next = buffer->next->next->next;
			ft_lstdelone(temp, &ps_free_content);
			ft_lstdelone(temp2, &ps_free_content);
		}
		else
			buffer = buffer->next;
	}
}

void	ps_optimize(t_list **op)
{
	int	i;

	ps_merge_op(*op);
	ps_replace_swap_op(*op);
	i = 0;
	while (i != ft_lstsize(*op))
	{
		i = ft_lstsize(*op);
		ps_remove_op(op);
	}
}
