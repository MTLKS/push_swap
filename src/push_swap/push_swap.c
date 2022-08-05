/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:52:45 by maliew            #+#    #+#             */
/*   Updated: 2022/08/05 19:48:51 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstindex(t_list *stack, int content);

int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = ps_get_stack(argc, argv);
	ps_index_stack(&stack);
	ps_sort_stack(&stack);
	// ft_printf("%d", ft_lstindex(stack, 0));
	ft_lstclear(&stack, &ps_free_content);
}
