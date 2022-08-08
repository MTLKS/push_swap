/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:53:42 by maliew            #+#    #+#             */
/*   Updated: 2022/08/08 21:33:20 by maliew           ###   ########.fr       */
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

	while (list)
	{
		if (*(int *)list->content > temp)
			temp = *(int *)list->content;
		list = list->next;
	}
	return (temp);
}
