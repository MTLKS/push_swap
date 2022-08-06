/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:11:26 by maliew            #+#    #+#             */
/*   Updated: 2022/08/06 22:35:28 by maliew           ###   ########.fr       */
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

void	ps_insert_sort_ba(t_list **a, t_list **b, float min, float max)
{
	while (ps_lst_hasrange(*b, min, max))
	{
		if (!(*a) || (b && *(int *)(*b)->content == *((int *)(*a)->content) - 1))
			ps_operate(a, b, PA);
		if (!*b || *(int *)(*a)->content - 1 < min)
			break ;
		if (ps_lst_index(*b, *(int *)(*a)->content - 1) < ft_lstsize(*b) / 2)
			ps_operate(a, b, RB);
		else
			ps_operate(a, b, RRB);
	}
}

void	ps_push_stack_a(t_list **a, t_list **b, float min, float max)
{
	float	curr;
	float	last;

	while (ps_lst_hasrange(*b, min, max))
	{
		if (b && *(int *)(*b)->content >= min && *(int *)(*b)->content < max)
			ps_operate(a, b, PA);
		if (!*b)
			break ;
		curr = *(int *)(*b)->content;
		last = *(int *)(ft_lstlast(*b))->content;
		if ((curr < min || curr >= max) && last >= min && last < max)
			ps_operate(a, b, RRB);
	}
}

void	ps_push_stack_b(t_list **a, t_list **b, float min, float max)
{
	float	curr;
	float	last;

	while (ps_lst_hasrange(*a, min, max))
	{
		if (a && *(int *)(*a)->content >= min && *(int *)(*a)->content < max)
			ps_operate(a, b, PB);
		if (!*a)
			break ;
		curr = *(int *)(*a)->content;
		last = *(int *)(ft_lstlast(*a))->content;
		if ((curr < min || curr >= max) && last >= min && last < max)
			ps_operate(a, b, RRA);
	}
}

void	ps_split_stack_ab(t_list **a, t_list **b, float min, float max)
{
	float	midpoint;
	int		max_int;

	midpoint = (max + min) / 2;
	if (midpoint >= max - 1)
		return ;
	while (a && ps_lst_hasrange(*a, 0, midpoint))
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
	max_int = ps_round(max) + (max == ps_round(max));
	while (ps_lst_index(*a, max_int) <= (max - min) / 2
		&& ps_lst_index(*a, max_int) != -1)
		ps_operate(a, b, RRA);
	ps_split_stack_ab(a, b, midpoint, max);
}
