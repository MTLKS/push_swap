/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_quicksort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:51:19 by maliew            #+#    #+#             */
/*   Updated: 2022/08/10 20:41:57 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_swap_content(t_list *a, t_list *b)
{
	void	*temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

static t_list	*ps_partition(t_list *first, t_list *last)
{
	t_list	*front;
	t_list	*pivot;

	pivot = first;
	front = first;
	while (front && front != last)
	{
		if (*((int *)(front->content)) < *((int *)(last->content)))
		{
			pivot = first;
			ps_swap_content(first, front);
			first = first->next;
		}
		front = front->next;
	}
	ps_swap_content(first, last);
	return (pivot);
}

void	ps_list_quicksort(t_list *first, t_list *last)
{
	t_list	*pivot;

	if (first == last)
		return ;
	pivot = ps_partition(first, last);
	if (pivot && pivot->next)
		ps_list_quicksort(pivot->next, last);
	if (pivot && first != pivot)
		ps_list_quicksort(first, pivot);
}
