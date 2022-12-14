/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smart_insert_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:12:43 by maliew            #+#    #+#             */
/*   Updated: 2022/08/13 20:02:49 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	counts the cost to insert n into stack

	a postive result (i) means that
	the stack will need to be rotated i times

	a negative result (i) means that
	stack will need to be rotated in reverse i times
*/
static int	ps_count_cost(t_list *stack, int n)
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

/*
	finds the min cost to push one element from B to A

	goes through all elements from closest to furthest of stack B
	finds the rotations on stack A need to push element from stack B to A

	calculates the total cost
		if rotates the same direction
			max(cost of A, cost of B)
		else
			cost of A + cost of B
	
	Reason of calculation:
		Same direction:
			A		: ra ra ra ra	= 4
			B		: rb rb rb		= 3
			Combined: rr rr rr ra	= 4
		
		Different direction:
			A		: ra ra ra ra	= 4
			B		: rrb rrb rrb	= 3
			Combined: ra ra ra ra rrb rrb rrb = 7
*/
static void	ps_get_min_cost(t_list **a, t_list **b, t_list **r, int *min)
{
	int	*curr;

	curr = (int *)malloc(3 * sizeof(int));
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
	free(curr);
}

static void	ps_init_move(int *move_a, int *move_b, int *cost)
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

/*
	executes the operations based on the cost for stack a and stack b,
	combining if possible

	pushes one element from stack b to stack a
*/
static void	ps_smart_insert_op(t_ps_list **ps_list, int *cost)
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

/*
	inserts elements in current range (min <= n < max) from B to A

	finds the amount of moves required for each element
	executes the moves for the element that requires the least amount
	removes the current range
*/
void	ps_smart_insert_stack(t_ps_list **ps_list, t_list **r)
{
	int		*min;
	t_list	**a;
	t_list	**b;
	t_list	*curr_range;

	a = &(*ps_list)->stack_a;
	b = &(*ps_list)->stack_b;
	min = (int *)malloc(3 * sizeof(int));
	while (ps_lst_hasrange(*b, ps_range_get(*r, 0), ps_range_get(*r, 1)))
	{
		min[0] = INT_MAX;
		min[1] = 0;
		min[2] = 0;
		ps_get_min_cost(a, b, r, min);
		ps_smart_insert_op(ps_list, min);
	}
	curr_range = *r;
	*r = (*r)->next;
	ft_lstdelone(curr_range, ps_free_content);
	free(min);
}
