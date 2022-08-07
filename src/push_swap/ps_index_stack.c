/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:14:51 by maliew            #+#    #+#             */
/*   Updated: 2022/08/07 12:08:03 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ps_new_content(int count)
{
	int	*num;

	num = (int *)malloc(sizeof(int));
	*num = count;
	return (num);
}

void	ps_index_stack(t_list **stack)
{
	t_list	*sorted_stack;
	t_list	*sorted_buffer;
	t_list	*buffer;
	int		count;

	sorted_stack = ft_lstmap(*stack, &ps_return_content, &ps_free_content);
	ps_quick_sort(sorted_stack, ft_lstlast(sorted_stack));
	buffer = *stack;
	while (buffer)
	{
		sorted_buffer = sorted_stack;
		count = 0;
		while (sorted_buffer)
		{
			if (*((int *)buffer->content) == *((int *)sorted_buffer->content))
			{
				buffer->content = ps_new_content(count);
				break ;
			}
			sorted_buffer = sorted_buffer->next;
			count++;
		}
		buffer = buffer->next;
	}
	ft_lstclear(&sorted_stack, &ps_free_content);
}
