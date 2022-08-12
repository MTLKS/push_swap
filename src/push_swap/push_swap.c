/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:52:45 by maliew            #+#    #+#             */
/*   Updated: 2022/08/11 02:16:29 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_list	*ps_list;
	t_list		*stack;

	if (argc == 1)
		return (0);
	stack = ps_get_stack(argc, argv);
	ps_checkdupe(stack);
	if (ps_lst_issorted(stack))
	{
		ft_lstclear(&stack, &ps_free_content);
		return (0);
	}
	ps_index_stack(&stack);
	ps_list = (t_ps_list *)malloc(sizeof(t_ps_list));
	ps_list->stack_a = stack;
	ps_list->stack_b = NULL;
	ps_list->operations = NULL;
	ps_sort_stack(&ps_list);
	ps_optimize(&ps_list->operations);
	ft_lstiter(ps_list->operations, &ps_oplst_print);
	ft_lstclear(&ps_list->stack_a, &ps_free_content);
	ft_lstclear(&ps_list->stack_b, &ps_free_content);
	ft_lstclear(&ps_list->operations, &ps_free_content);
	free(ps_list);
}
