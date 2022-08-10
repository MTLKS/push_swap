/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimize_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 01:14:08 by maliew            #+#    #+#             */
/*   Updated: 2022/08/11 01:22:16 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_replace_and_delete(t_list *buffer, int move)
{
	t_list	*temp;

	temp = buffer->next;
	*(int *)buffer->content = move;
	buffer->next = buffer->next->next;
	ft_lstdelone(temp, &ps_free_content);
}


void	ps_replace_and_delete2(t_list *buffer, int move)
{
	t_list	*temp;

	temp = buffer->next->next;
	*(int *)buffer->content = move;
	buffer->next->next = buffer->next->next->next;
	ft_lstdelone(temp, &ps_free_content);
}
