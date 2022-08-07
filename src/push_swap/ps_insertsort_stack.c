/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertsort_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:39:19 by maliew            #+#    #+#             */
/*   Updated: 2022/08/07 14:16:16 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_stack_b(t_ps_list **ps_list, float min, float max)
{
	float	curr;
	float	last;
	t_list	**a;

	a = &(*ps_list)->stack_a;
	while (ps_lst_hasrange(*a, min, max))
	{
		if (a && *(int *)(*a)->content >= min && *(int *)(*a)->content < max)
			ps_operate(ps_list, PB);
		if (!*a)
			break ;
		curr = *(int *)(*a)->content;
		last = *(int *)(ft_lstlast(*a))->content;
		if ((curr < min || curr >= max) && last >= min && last < max)
			ps_operate(ps_list, RRA);
	}
}

void	ps_insertsort_stack_100(t_ps_list **ps_list)
{
	float	len;

	(*ps_list)->stack_b = NULL;
	len = ft_lstsize((*ps_list)->stack_a);
	ps_split_stack_ab(ps_list, 0, len);
	ps_insert_sort_ba(ps_list, 0, len);
}
