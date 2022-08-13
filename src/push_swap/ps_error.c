/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:36:29 by maliew            #+#    #+#             */
/*   Updated: 2022/08/13 18:30:04 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_exiterror(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ps_checkdupe(t_list *stack)
{
	t_list	*i;
	t_list	*j;

	i = stack;
	while (i && i->next)
	{
		j = i->next;
		while (j)
		{
			if (*(int *)i->content == *(int *)j->content)
			{
				ft_lstclear(&stack, &ps_free_content);
				ps_exiterror();
			}
			j = j->next;
		}
		i = i->next;
	}
}

static int	ps_checkstr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ps_checkarr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		if (ps_checkstr(arr[i]))
			return (1);
		if (ps_atol(arr[i]) != ft_atoi(arr[i]))
			return (1);
	}
	return (i == 0);
}
