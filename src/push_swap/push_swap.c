/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:52:45 by maliew            #+#    #+#             */
/*   Updated: 2022/08/07 14:31:36 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_list	*ps_list;
	t_list		*stack;

	stack = ps_get_stack(argc, argv);
	ps_index_stack(&stack);
	ps_list = (t_ps_list *)malloc(sizeof(t_ps_list));
	ps_list->stack_a = stack;
	ps_list->stack_b = NULL;
	ps_list->operations = NULL;
	ps_insertsort_stack_100(&ps_list);
	ft_lstiter(ps_list->operations, &ps_oplst_print);
	ft_lstclear(&ps_list->stack_a, &ps_free_content);
	ft_lstclear(&ps_list->stack_b, &ps_free_content);
	ft_lstclear(&ps_list->operations, &ps_free_content);
	free(ps_list);
}
