/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:48:56 by maliew            #+#    #+#             */
/*   Updated: 2022/08/13 19:44:07 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	allocates memory for an integer and returns the pointer
*/
static int	*ps_new_content(int count)
{
	int	*num;

	num = (int *)malloc(sizeof(int));
	*num = count;
	return (num);
}

/*
	changes the values in a linked list to the index if it is sorted
*/
void	ps_index_stack(t_list **stack)
{
	t_list	*sorted_stack;
	t_list	*buffer;

	sorted_stack = ft_lstmap(*stack, &ps_return_content, &ps_free_content);
	ps_list_quicksort(sorted_stack, ft_lstlast(sorted_stack));
	buffer = *stack;
	while (buffer)
	{
		buffer->content = ps_new_content(
				ps_lst_index(sorted_stack, ps_lst_value(buffer, 0)));
		buffer = buffer->next;
	}
	ft_lstclear(&sorted_stack, &ps_free_content);
}

static void	ps_free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

/*
	adds the integer value of each string in an array to the back of a
	linked list
*/
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

/*
	returns a linked list of integers from an array of strings
*/
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
