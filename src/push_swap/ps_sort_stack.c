/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:57:28 by maliew            #+#    #+#             */
/*   Updated: 2022/08/13 13:51:59 by maliew           ###   ########.fr       */
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

// static void	ps_insert_stack(t_ps_list **ps_list, t_list **range)
// {
// 	t_list	*curr_range;
// 	int		min;
// 	int		max;

// 	curr_range = *range;
// 	min = ps_range_get(curr_range, 0);
// 	max = ps_range_get(curr_range, 1);
// 	ps_insert_op(ps_list, min, max);
// 	*range = (*range)->next;
// 	ft_lstdelone(curr_range, ps_free_content);
// }

int	ps_count_cost(t_list *stack, int n)
{
	int	i;
	int	curr;
	int	prev;

	if (!ft_lstsize(stack))
		return (0);
	i = 0;
	curr = ps_lst_value(stack, i);
	prev = ps_lst_value(stack, i - 1);
	while (!((n < curr && n > prev)
			|| (n < curr && prev == ps_lst_max(stack))
			|| (n > prev && curr == ps_lst_min(stack))))
	{
		i = -i;
		if (i >= 0)
			i++;
		curr = ps_lst_value(stack, i);
		prev = ps_lst_value(stack, i - 1);
	}
	return (i);
}

int	ps_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ps_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ps_copy_arr(int count, int *from, int *to)
{
	while (count--)
		to[count] = from[count];
}

void	ps_init_move(int *move_a, int *move_b, int *cost)
{
	if (cost[1] >= 0)
		*move_a = RA;
	else
		*move_a = RRA;
	if (cost[2] >= 0)
		*move_b = RB;
	else
		*move_b = RRB;
}

void	ps_smart_insert_op(t_ps_list **ps_list, int *cost)
{
	int	move_a;
	int	move_b;

	ps_init_move(&move_a, &move_b, cost);
	while (cost[1] > 0 && cost[2] > 0)
	{
		ps_operate(ps_list, RR);
		cost[1]--;
		cost[2]--;
	}
	while (cost[1] < 0 && cost[2] < 0)
	{
		ps_operate(ps_list, RRR);
		cost[1]++;
		cost[2]++;
	}
	cost[1] = ps_abs(cost[1]) + 1;
	while (--cost[1])
		ps_operate(ps_list, move_a);
	cost[2] = ps_abs(cost[2]) + 1;
	while (--cost[2])
		ps_operate(ps_list, move_b);
	ps_operate(ps_list, PA);
}

static void	ps_smart_insert_stack(t_ps_list **ps_list, t_list **r)
{
	int		*min;
	int		*curr;
	t_list	**a;
	t_list	**b;
	t_list	*curr_range;

	a = &(*ps_list)->stack_a;
	b = &(*ps_list)->stack_b;
	min = (int *)malloc(3 * sizeof(int));
	curr = (int *)malloc(3 * sizeof(int));
	while (ps_lst_hasrange(*b, ps_range_get(*r, 0), ps_range_get(*r, 1)))
	{
		min[0] = INT_MAX;
		min[1] = 0;
		min[2] = 0;
		curr[0] = INT_MAX;
		curr[1] = 0;
		curr[2] = 0;
		while (ps_abs(curr[2]) < ft_lstsize(*b) && ps_abs(curr[2]) < min[0])
		{
			if (ps_lst_value(*b, curr[2]) >= ps_range_get(*r, 0)
				&& ps_lst_value(*b, curr[2]) < ps_range_get(*r, 1))
			{
				curr[1] = ps_count_cost(*a, ps_lst_value(*b, curr[2]));
				if (curr[1] * curr[2] >= 0)
					curr[0] = ps_max(ps_abs(curr[1]), ps_abs(curr[2]));
				else
					curr[0] = ps_abs(curr[1]) + ps_abs(curr[2]);
				if (curr[0] < min[0])
					ps_copy_arr(3, curr, min);
			}
			curr[2] = -curr[2];
			if (curr[2] >= 0)
				curr[2]++;
		}
		ps_smart_insert_op(ps_list, min);
	}
	curr_range = *r;
	*r = (*r)->next;
	ft_lstdelone(curr_range, ps_free_content);
	free(min);
	free(curr);
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

void	ps_sort_stack(t_ps_list **ps_list)
{
	t_list	*range;

	range = ft_lstnew(ps_range_new(0, ft_lstsize((*ps_list)->stack_a)));
	(*ps_list)->stack_b = NULL;
	ps_split_stack(ps_list, &range);
	while (range)
	{
		if (ps_range_get(range, 1) - ps_range_get(range, 0) > MIN_STACK_SIZE)
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
