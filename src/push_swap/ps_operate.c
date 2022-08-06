/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:46:29 by maliew            #+#    #+#             */
/*   Updated: 2022/08/06 21:47:11 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* temp function */
void	print_op(int operator)
{
	if (operator == PA)
		ft_printf("pa");
	else if (operator == PB)
		ft_printf("pb");
	else if (operator == SA)
		ft_printf("sa");
	else if (operator == SB)
		ft_printf("sb");
	else if (operator == SS)
		ft_printf("ss");
	else if (operator == RA)
		ft_printf("ra");
	else if (operator == RB)
		ft_printf("rb");
	else if (operator == RR)
		ft_printf("rr");
	else if (operator == RRA)
		ft_printf("rra");
	else if (operator == RRB)
		ft_printf("rrb");
	else if (operator == RRR)
		ft_printf("rrr");
	ft_printf(" ");
}

void	ps_operate(t_list **stack_a, t_list **stack_b, int operator)
{
	void	(*f)(t_list **stack);

	if (operator & PX)
	{
		if (operator & XA)
			ps_push(stack_b, stack_a);
		else
			ps_push(stack_a, stack_b);
	}
	else
	{
		if (operator & SX)
			f = &ps_swap;
		else if (operator & RX)
			f = &ps_rotate;
		else if (operator & RRX)
			f = &ps_reverse_rotate;
		if (operator & XA)
			f(stack_a);
		if (operator & XB)
			f(stack_b);
	}
	print_op(operator);
}
