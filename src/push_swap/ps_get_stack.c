/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:48:56 by maliew            #+#    #+#             */
/*   Updated: 2022/08/05 02:50:49 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_stack(t_list **stack, char **arr)
{
	int	i;
	int	*num;

	i = -1;
	while (arr[++i])
	{
		num = (int *)malloc(sizeof(int));
		*num = ft_atoi(arr[i]);
		ft_lstadd_back(stack, ft_lstnew(num));
	}
}

static void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

t_list	*ps_get_stack(int argc, char **argv)
{
	t_list	*stack;
	char	**arr;
	int		i;

	i = 0;
	stack = NULL;
	while (++i < argc)
	{
		arr = ft_split(argv[i], ' ');
		add_stack(&stack, arr);
		free_arr(arr);
	}
	return (stack);
}
