/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:19:34 by maliew            #+#    #+#             */
/*   Updated: 2022/08/06 22:30:13 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_push_push_sort(t_list **a, t_list **b, float min, float max)
{
	ps_push_stack_a(a, b, min, max);
	ps_split_stack_ab(a, b, min, ps_round(max));
	ps_insert_sort_ba(a, b, min, max);
}

void	ps_sort_stack_100(t_list **stack_a)
{
	t_list	*stack_b;
	float	len;

	stack_b = NULL;
	len = ft_lstsize(*stack_a);
	ps_push_stack_b(stack_a, &stack_b, 0, len);
	ps_insert_sort_ba(stack_a, &stack_b, 0, len);
}

void	ps_sort_stack_500(t_list **stack_a)
{
	t_list	*stack_b;
	float	len;

	stack_b = NULL;
	len = ft_lstsize(*stack_a);
	ps_split_stack_ab(stack_a, &stack_b, 0, len);
	ps_insert_sort_ba(stack_a, &stack_b, len * 0.75, len);
	ps_push_push_sort(stack_a, &stack_b, len * 0.625, len * 0.75);
	ps_push_push_sort(stack_a, &stack_b, len * 0.5, len * 0.625);
	ps_push_push_sort(stack_a, &stack_b, len * 0.25, len * 0.5);
	ps_push_push_sort(stack_a, &stack_b, 0, len * 0.25);
}
