/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:11:26 by maliew            #+#    #+#             */
/*   Updated: 2022/08/13 03:13:06 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_insert_op(t_ps_list **ps_list, int min, int max)
{
	t_list	**a;
	t_list	**b;

	a = &(*ps_list)->stack_a;
	b = &(*ps_list)->stack_b;
	while (ps_lst_hasrange(*b, min, max))
	{
		if (!(*a)
			|| (b && ps_lst_value(*b, 0) == ps_lst_value(*a, 0) - 1))
			ps_operate(ps_list, PA);
		if (!*b || ps_lst_value(*a, 0) - 1 < min)
			break ;
		if (!(b && ps_lst_value(*b, 0) == ps_lst_value(*a, 0) - 1))
		{
			if (ps_lst_index(*b, ps_lst_value(*a, 0) - 1)
				< ft_lstsize(*b) / 2)
				ps_operate(ps_list, RB);
			else
				ps_operate(ps_list, RRB);
		}
	}
}

void	ps_push_op(t_ps_list **ps_list, int min, int max)
{
	t_list	**b;

	b = &(*ps_list)->stack_b;
	while (ps_lst_hasrange(*b, min, max))
	{
		if (b && *(int *)(*b)->content >= min && *(int *)(*b)->content < max)
			ps_operate(ps_list, PA);
		else
		{
			if (ps_lst_indexinrange((*b), min, max) < ft_lstsize(*b) / 2)
				ps_operate(ps_list, RB);
			else
				ps_operate(ps_list, RRB);
		}
	}
}

void	ps_split_op(t_ps_list **ps_list, int min, int max)
{
	t_list	**a;
	t_list	**b;

	a = &(*ps_list)->stack_a;
	b = &(*ps_list)->stack_b;
	while (a && ps_lst_hasrange(*a, min, max))
	{
		if (*((int *)(*a)->content) < max)
		{
			ps_operate(ps_list, PB);
			if (*(int *)(*b)->content < (min + max) / 2)
				ps_operate(ps_list, RB);
		}
		else
		{
			if (ps_lst_indexinrange((*a), min, max) < ft_lstsize(*a) / 2)
				ps_operate(ps_list, RA);
			else
				ps_operate(ps_list, RRA);
		}
	}
}

void	ps_push_last(t_ps_list **ps_list, int min, int max)
{
	while (ps_lst_hasrange((*ps_list)->stack_a, min, max))
	{
		if (ps_lst_indexinrange((*ps_list)->stack_a, min, max)
			> ft_lstsize((*ps_list)->stack_a) / 2)
			ps_operate(ps_list, RRA);
		ps_operate(ps_list, PB);
	}
}
