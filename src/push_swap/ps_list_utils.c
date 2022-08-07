/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:16:06 by maliew            #+#    #+#             */
/*   Updated: 2022/08/07 12:08:04 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_content(void *content)
{
	free(content);
}

void	*ps_return_content(void *content)
{
	return (content);
}

int	ps_lst_index(t_list *stack, float content)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (*(int *)stack->content == content)
			return (count);
		stack = stack->next;
		count++;
	}
	return (-1);
}

int	ps_lst_hasrange(t_list *stack, float min, float max)
{
	int	content;

	while (stack)
	{
		content = *((int *)stack->content);
		if (content >= min && content < max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ps_lst_issorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (*((int *)stack->content) > *((int *)stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}
