/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:33:51 by maliew            #+#    #+#             */
/*   Updated: 2022/08/13 17:33:02 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_sort_three(t_ps_list **ps_list)
{
	t_list	*a;
	int		x[3];

	a = (*ps_list)->stack_a;
	x[0] = ps_lst_value(a, 0);
	x[1] = ps_lst_value(a, 1);
	x[2] = ps_lst_value(a, 2);
	if (x[0] < x[2] && x[2] < x[1])
	{
		ps_operate(ps_list, RRA);
		ps_operate(ps_list, SA);
	}
	else if (x[1] < x[0] && x[0] < x[2])
		ps_operate(ps_list, SA);
	else if (x[2] < x[0] && x[0] < x[1])
		ps_operate(ps_list, RRA);
	else if (x[1] < x[2] && x[2] < x[0])
		ps_operate(ps_list, RA);
	else if (x[2] < x[1] && x[1] < x[0])
	{
		ps_operate(ps_list, RA);
		ps_operate(ps_list, SA);
	}
}

void	ps_sort_small(t_ps_list **ps_list)
{
	t_list	**a;
	t_list	*range;

	a = &(*ps_list)->stack_a;
	if (ft_lstsize(*a) == 2)
		ps_operate(ps_list, SA);
	else
	{
		range = ft_lstnew(ps_range_new(0, ft_lstsize(*a)));
		while (ft_lstsize(*a) > 3)
			ps_operate(ps_list, PB);
		ps_sort_three(ps_list);
		ps_smart_insert_stack(ps_list, &range);
		ps_loop_stack(ps_list);
		ft_lstclear(&range, &ps_free_content);
	}
}
