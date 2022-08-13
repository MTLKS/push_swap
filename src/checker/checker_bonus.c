/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:46:03 by maliew            #+#    #+#             */
/*   Updated: 2022/08/13 18:43:28 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_ps_list	*ps_list;
	t_list		*stack;
	int			ok;

	if (argc == 1)
		return (0);
	stack = ps_get_stack(argc, argv);
	ps_checkdupe(stack);
	ps_list = (t_ps_list *)malloc(sizeof(t_ps_list));
	ps_list->stack_a = stack;
	ps_list->stack_b = NULL;
	ps_read_and_operate(&ps_list);
	ok = ps_lst_issorted(ps_list->stack_a);
	ps_clear_pslist(&ps_list);
	if (ok)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
