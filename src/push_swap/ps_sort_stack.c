/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:57:28 by maliew            #+#    #+#             */
/*   Updated: 2022/08/10 20:59:17 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_push_stack(t_ps_list **ps_list, t_list **range)
{
	t_list	*curr_range;
	int		min;
	int		max;

	curr_range = *range;
	min = ps_range_get(curr_range, 0);
	max = ps_range_get(curr_range, 1);
	ps_push_op(ps_list, (min + max) / 2, max);
	*range = (*range)->next;
	ft_lstadd_front(range, ft_lstnew(ps_range_new(min, (min + max) / 2)));
	ft_lstadd_front(range, ft_lstnew(ps_range_new((min + max) / 2, max)));
	ft_lstdelone(curr_range, ps_free_content);
}

static void	ps_insert_stack(t_ps_list **ps_list, t_list **range)
{
	t_list	*curr_range;
	int		min;
	int		max;

	curr_range = *range;
	min = ps_range_get(curr_range, 0);
	max = ps_range_get(curr_range, 1);
	ps_insert_op(ps_list, min, max);
	*range = (*range)->next;
	ft_lstdelone(curr_range, ps_free_content);
}

static void	ps_split_stack(t_ps_list **ps_list, t_list **range)
{
	t_list	*curr_range;
	int		mid;
	int		max;
	int		min;

	curr_range = *range;
	min = ps_range_get(curr_range, 0);
	max = ps_range_get(curr_range, 1);
	*range = (*range)->next;
	ft_lstdelone(curr_range, ps_free_content);
	if (max - min == 1)
	{
		ps_push_last(ps_list, min, max);
		return ;
	}
	mid = (min + max) / 2;
	ps_split_op(ps_list, min, mid);
	ft_lstadd_front(range, ft_lstnew(ps_range_new(min, (min + mid) / 2)));
	ft_lstadd_front(range, ft_lstnew(ps_range_new((min + mid) / 2, mid)));
	ft_lstadd_front(range, ft_lstnew(ps_range_new(mid, max)));
	ps_split_stack(ps_list, range);
}

void	ps_sort_stack(t_ps_list **ps_list)
{
	t_list	*range;

	range = ft_lstnew(ps_range_new(0, ft_lstsize((*ps_list)->stack_a)));
	(*ps_list)->stack_b = NULL;
	ps_split_stack(ps_list, &range);
	while (range)
	{
		if (ps_range_get(range, 1) - ps_range_get(range, 0) > 20)
		{
			ps_push_stack(ps_list, &range);
			ps_split_stack(ps_list, &range);
		}
		else
			ps_insert_stack(ps_list, &range);
	}
	ft_lstclear(&range, ps_free_content);
}
