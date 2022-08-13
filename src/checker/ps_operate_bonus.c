/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:46:29 by maliew            #+#    #+#             */
/*   Updated: 2022/08/13 16:44:56 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ps_push(t_list **from, t_list **to)
{
	t_list	*temp;

	if (!*from)
		return ;
	temp = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = temp;
}

void	ps_swap(t_list **stack)
{
	t_list	*temp;

	if (ft_lstsize(*stack) < 2)
		return ;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	ft_lstadd_front(stack, temp);
}

void	ps_rotate(t_list **stack)
{
	t_list	*temp;

	if (ft_lstsize(*stack) < 2)
		return ;
	temp = (*stack)->next;
	ft_lstlast(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
}

void	ps_reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*buffer;

	if (ft_lstsize(*stack) < 2)
		return ;
	temp = ft_lstlast(*stack);
	buffer = *stack;
	while (buffer->next->next)
		buffer = buffer->next;
	buffer->next = NULL;
	temp->next = *stack;
	*stack = temp;
}

void	ps_operate(t_ps_list **ps_list, int move)
{
	void	(*f)(t_list **stack);

	if (move & PX)
	{
		if (move & XA)
			ps_push(&(*ps_list)->stack_b, &(*ps_list)->stack_a);
		else
			ps_push(&(*ps_list)->stack_a, &(*ps_list)->stack_b);
	}
	else
	{
		if (move & SX)
			f = &ps_swap;
		else if (move & RX)
			f = &ps_rotate;
		else if (move & RRX)
			f = &ps_reverse_rotate;
		if (move & XA)
			f(&(*ps_list)->stack_a);
		if (move & XB)
			f(&(*ps_list)->stack_b);
	}
}
