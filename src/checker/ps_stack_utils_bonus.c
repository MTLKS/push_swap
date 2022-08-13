/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:48:56 by maliew            #+#    #+#             */
/*   Updated: 2022/08/13 17:29:32 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ps_free_content(void *content)
{
	free(content);
}

static void	ps_free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

static void	ps_add_stack(t_list **stack, char **arr)
{
	int		i;
	int		*num;

	i = -1;
	while (arr[++i])
	{
		num = (int *)malloc(sizeof(int));
		*num = ft_atoi(arr[i]);
		ft_lstadd_back(stack, ft_lstnew(num));
	}
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
		if (ps_checkarr(arr))
		{
			ps_free_arr(arr);
			ft_lstclear(&stack, &ps_free_content);
			ps_exiterror();
		}
		ps_add_stack(&stack, arr);
		ps_free_arr(arr);
	}
	return (stack);
}

int	*ps_range_new(int min, int max)
{
	int	*range;

	range = (int *)malloc(2 * sizeof(int));
	range[0] = min;
	range[1] = max;
	return (range);
}
