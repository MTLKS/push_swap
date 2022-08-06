/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:52:45 by maliew            #+#    #+#             */
/*   Updated: 2022/08/06 22:41:42 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = ps_get_stack(argc, argv);
	ps_index_stack(&stack);
	// if (ft_lstsize(stack) <= 100)
	// 	ps_sort_stack_100(&stack);
	// else
		ps_sort_stack_500(&stack);
	// ft_lstiter(stack, ps_print_stack);
	ft_lstclear(&stack, &ps_free_content);
}
