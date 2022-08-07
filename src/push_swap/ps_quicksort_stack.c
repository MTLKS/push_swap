/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:57:28 by maliew            #+#    #+#             */
/*   Updated: 2022/08/07 14:01:15 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_push_push_sort(t_ps_list **ps_list, float min, float max)
{
	ps_push_stack_a(ps_list, min, max);
	ps_split_stack_ab(ps_list, min, ps_round(max));
	ps_insert_sort_ba(ps_list, min, max);
}

void	ps_quicksort_stack_100(t_ps_list **ps_list)
{
	float	len;

	(*ps_list)->stack_b = NULL;
	len = ft_lstsize((*ps_list)->stack_a);
	ps_split_stack_ab(ps_list, 0, len);
	ps_insert_sort_ba(ps_list, len * 0.5, len);
	ps_push_push_sort(ps_list, 0, len * 0.5);
}

void	ps_quicksort_stack(t_ps_list **ps_list)
{
	float	len;

	(*ps_list)->stack_b = NULL;
	len = ft_lstsize((*ps_list)->stack_a);
	ps_split_stack_ab(ps_list, 0, len);
	ps_insert_sort_ba(ps_list, len * 0.75, len);
	ps_push_push_sort(ps_list, len * 0.625, len * 0.75);
	ps_push_push_sort(ps_list, len * 0.5, len * 0.625);
	ps_push_push_sort(ps_list, len * 0.25, len * 0.5);
	ps_push_push_sort(ps_list, 0, len * 0.25);
}
