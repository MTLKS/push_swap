/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:19:34 by maliew            #+#    #+#             */
/*   Updated: 2022/08/05 22:00:22 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstindex(t_list *stack, int content)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (*(int *)stack->content == content)
			return (count);
		stack = stack->next;
		count++;
	}
	return (-1);
}

int	stack_has_nodes_in_range(t_list *stack, int min, int max)
{
	while (stack)
	{
		if (*((int *)stack->content) >= min && *((int *)stack->content) < max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	sort_back_a(t_list **a, t_list **b, int min, int max)
{
	while (stack_has_nodes_in_range(*b, min, max))
	{
		if (b && *(int *)(*b)->content == *((int *)(*a)->content) - 1)
			ps_operate(a, b, PA);
		if (!*b)
			break ;
	}
}

void	push_stack_b(t_list **a, t_list **b, int min, int max)
{
	int	midpoint;

	midpoint = (max + min) / 2;
	if (midpoint >= max - 1)
		return ;
	while (a && stack_has_nodes_in_range(*a, 0, midpoint))
	{
		if (*((int *)(*a)->content) < midpoint)
		{
			ps_operate(a, b, PB);
			if (*(int *)(*b)->content < midpoint - (max - midpoint) / 2)
				ps_operate(a, b, RB);
		}
		else
			ps_operate(a, b, RA);
	}
	push_stack_b(a, b, midpoint, max);
}

void	ps_sort_stack(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	push_stack_b(stack_a, &stack_b, 0, ft_lstsize(*stack_a));
}
