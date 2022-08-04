/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:52:45 by maliew            #+#    #+#             */
/*   Updated: 2022/08/05 03:45:54 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*stack_b;

	stack = ps_get_stack(argc, argv);
	stack_b = NULL;
	ft_printf("Stack input:\n");
	ft_lstiter(stack, &ps_print_stack);
	ft_printf("\n\n");
	ps_index_stack(&stack);
	ft_printf("Stack index:\n");
	ft_lstiter(stack, &ps_print_stack);
	ft_printf("\n\n");
	ps_quick_sort(stack, ft_lstlast(stack));
	ft_printf("Stack output:\n");
	ft_lstiter(stack, &ps_print_stack);
	ft_printf("\n");
	ft_lstiter(stack_b, &ps_print_stack);
	ft_printf("\n");
	ft_lstclear(&stack, &ps_free_content);
	ft_lstclear(&stack_b, &ps_free_content);
}
