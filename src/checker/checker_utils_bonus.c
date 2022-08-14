/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:12:29 by maliew            #+#    #+#             */
/*   Updated: 2022/08/14 14:46:09 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ps_exiterror_pslist(t_ps_list **ps_list)
{
	ps_clear_pslist(ps_list);
	ps_exiterror();
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

void	ps_clear_pslist(t_ps_list **ps_list)
{
	ft_lstclear(&(*ps_list)->stack_a, &ps_free_content);
	ft_lstclear(&(*ps_list)->stack_b, &ps_free_content);
	free(*ps_list);
}

static void	ps_operate_string(t_ps_list **ps_list, char *move)
{
	if (ft_strncmp(move, "pa", ft_strlen(move) - 1) == 0)
		ps_operate(ps_list, PA);
	else if (ft_strncmp(move, "pb", ft_strlen(move) - 1) == 0)
		ps_operate(ps_list, PB);
	else if (ft_strncmp(move, "sa", ft_strlen(move) - 1) == 0)
		ps_operate(ps_list, SA);
	else if (ft_strncmp(move, "sb", ft_strlen(move) - 1) == 0)
		ps_operate(ps_list, SB);
	else if (ft_strncmp(move, "ss", ft_strlen(move) - 1) == 0)
		ps_operate(ps_list, SS);
	else if (ft_strncmp(move, "ra", ft_strlen(move) - 1) == 0)
		ps_operate(ps_list, RA);
	else if (ft_strncmp(move, "rb", ft_strlen(move) - 1) == 0)
		ps_operate(ps_list, RB);
	else if (ft_strncmp(move, "rr", ft_strlen(move) - 1) == 0)
		ps_operate(ps_list, RR);
	else if (ft_strncmp(move, "rra", ft_strlen(move) - 1) == 0)
		ps_operate(ps_list, RRA);
	else if (ft_strncmp(move, "rrb", ft_strlen(move) - 1) == 0)
		ps_operate(ps_list, RRB);
	else if (ft_strncmp(move, "rrr", ft_strlen(move) - 1) == 0)
		ps_operate(ps_list, RRR);
	else
		ps_exiterror_pslist(ps_list);
}

void	ps_read_and_operate(t_ps_list **ps_list)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		ps_operate_string(ps_list, move);
		free(move);
		move = get_next_line(0);
	}
}
