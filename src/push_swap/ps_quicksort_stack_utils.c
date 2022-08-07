/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort_stack_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:11:26 by maliew            #+#    #+#             */
/*   Updated: 2022/08/07 20:46:08 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_round(float f)
{
	int	i;

	i = f * 10;
	if (i % 10 >= 5)
		return ((int)f + 1);
	return ((int)f);
}

void	ps_insert_sort_ba(t_ps_list **ps_list, float min, float max)
{
	t_list	**a;
	t_list	**b;

	a = &(*ps_list)->stack_a;
	b = &(*ps_list)->stack_b;
	while (ps_lst_hasrange(*b, min, max))
	{
		if (!(*a)
			|| (b && *(int *)(*b)->content == *((int *)(*a)->content) - 1))
			ps_operate(ps_list, PA);
		if (!*b || *(int *)(*a)->content - 1 < min)
			break ;
		if (!(b && *(int *)(*b)->content == *((int *)(*a)->content) - 1))
		{
			if (ps_lst_index(*b, *(int *)(*a)->content - 1)
				< ft_lstsize(*b) / 2)
				ps_operate(ps_list, RB);
			else
				ps_operate(ps_list, RRB);
		}
	}
}

void	ps_push_stack_a(t_ps_list **ps_list, float min, float max)
{
	float	curr;
	float	last;
	t_list	**b;

	b = &(*ps_list)->stack_b;
	while (ps_lst_hasrange(*b, min, max))
	{
		if (b && *(int *)(*b)->content >= min && *(int *)(*b)->content < max)
			ps_operate(ps_list, PA);
		if (!*b)
			break ;
		curr = *(int *)(*b)->content;
		last = *(int *)(ft_lstlast(*b))->content;
		if ((curr < min || curr >= max) && last >= min && last < max)
			ps_operate(ps_list, RRB);
	}
}

void	ps_split_stack_ab(t_ps_list **ps_list, float min, float max)
{
	float	midpoint;
	int		max_int;

	midpoint = (max + min) / 2;
	if (midpoint >= max - 1)
		return ;
	while ((*ps_list)->stack_a
		&& ps_lst_hasrange((*ps_list)->stack_a, 0, midpoint))
	{
		if (*((int *)(*ps_list)->stack_a->content) < midpoint)
		{
			ps_operate(ps_list, PB);
			if (*(int *)(*ps_list)->stack_b->content
				< midpoint - (max - midpoint) / 2)
				ps_operate(ps_list, RB);
		}
		else
			ps_operate(ps_list, RA);
	}
	max_int = ps_round(max) + (max == ps_round(max));
	while (ps_lst_index((*ps_list)->stack_a, max_int) <= (max - min) / 2
		&& ps_lst_index((*ps_list)->stack_a, max_int) != -1)
		ps_operate(ps_list, RRA);
	ps_split_stack_ab(ps_list, midpoint, max);
}
