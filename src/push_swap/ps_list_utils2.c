/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:53:42 by maliew            #+#    #+#             */
/*   Updated: 2022/08/10 20:48:23 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ps_lst_get(t_list *list, int index)
{
	int	i;
	int	len;

	if (index >= 0)
	{
		i = -1;
		while (++i < index && list)
			list = list->next;
	}
	else
	{
		i = -1;
		len = ft_lstsize(list);
		while (++i < len + index && list)
			list = list->next;
	}
	return (list);
}

int	ps_lst_value(t_list *list, int index)
{
	return ((*(int *)ps_lst_get(list, index)->content));
}

int	ps_lst_min(t_list *list)
{
	int	temp;

	temp = INT_MAX;
	while (list)
	{
		if (*(int *)list->content < temp)
			temp = *(int *)list->content;
		list = list->next;
	}
	return (temp);
}

int	ps_lst_max(t_list *list)
{
	int	temp;

	temp = INT_MIN;
	while (list)
	{
		if (*(int *)list->content > temp)
			temp = *(int *)list->content;
		list = list->next;
	}
	return (temp);
}

int	ps_lst_indexinrange(t_list *list, int min, int max)
{
	int	count;

	count = 0;
	while (list)
	{
		if (*(int *)list->content >= min && *(int *)list->content < max)
			break ;
		list = list->next;
		count++;
	}
	return (count);
}
