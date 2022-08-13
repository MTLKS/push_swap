/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:57:28 by maliew            #+#    #+#             */
/*   Updated: 2022/08/13 20:07:20 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	pushes upper half of the elements in current range (min <= n < max)
	from stack b to stack a

	create new ranges of upper and lower half of current range and delete
	current range

	Example :
	Before : [250,500]->[0,250]
	After  : [375,500]->[250,375]->[0,250]
*/
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

/*
	pushes lower half of the elements in current range (min <= n < max)
	from stack a to stack b
	if n < (25% of range), split to the bottom of stack b

	creates 3 new ranges and deletes current range:
	1. [min, 25%]
	2. [25%, 50%]
	3. [50%, max]

	runs recursively until current stack has 1 element left, pushes element
	from stack a to stack b

	Example :
	Before : [0,10]
	Step 1 : [5,10]->[2,5]->[0,2]
	Step 2 : [7,10]->[6,7]->[5,6]->[2,5]->[0,2]
	Step 3 : [8,10]->[7,8]->[7,7]->[6,7]->[5,6]->[2,5]->[0,2]
	Step 4 : [9,10]->[8,9]->[8,8]->[7,8]->[7,7]->[6,7]->[5,6]->[2,5]->[0,2]
	End.
*/
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
	if (max - min < 2)
	{
		ps_push_last(ps_list, min, max);
		ft_lstadd_front(range, ft_lstnew(ps_range_new(min, max)));
		return ;
	}
	mid = (min + max) / 2;
	ps_split_op(ps_list, min, mid);
	ft_lstadd_front(range, ft_lstnew(ps_range_new(min, (min + mid) / 2)));
	ft_lstadd_front(range, ft_lstnew(ps_range_new((min + mid) / 2, mid)));
	ft_lstadd_front(range, ft_lstnew(ps_range_new(mid, max)));
	ps_split_stack(ps_list, range);
}

/*
	loops stack until element with value 0 is at the top
*/
void	ps_loop_stack(t_ps_list **ps_list)
{
	t_list	**a;
	int		len;

	a = &(*ps_list)->stack_a;
	len = ft_lstsize(*a);
	while (ps_lst_value(*a, 0) != 0)
	{
		if (ps_lst_index(*a, 0) < len / 2)
			ps_operate(ps_list, RA);
		else
			ps_operate(ps_list, RRA);
	}
}

/*
	creates range from 0 to length of stack A
	splits stack A to stack B
	checks current range
		if it exceeds MAX_STACK_SIZE
			push half of range back to A and split to B
		if not
			inserts range from B to A
	runs until no more ranges left
	loop stack until 0 is at the top
	stack is now sorted
	frees range
*/
void	ps_sort_stack(t_ps_list **ps_list)
{
	t_list	*range;

	range = ft_lstnew(ps_range_new(0, ft_lstsize((*ps_list)->stack_a)));
	(*ps_list)->stack_b = NULL;
	ps_split_stack(ps_list, &range);
	while (range)
	{
		if (ps_range_get(range, 1) - ps_range_get(range, 0) > MAX_STACK_SIZE)
		{
			ps_push_stack(ps_list, &range);
			ps_split_stack(ps_list, &range);
		}
		else
			ps_smart_insert_stack(ps_list, &range);
	}
	ps_loop_stack(ps_list);
	ft_lstclear(&range, ps_free_content);
}
