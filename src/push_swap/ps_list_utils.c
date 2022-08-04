/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:16:06 by maliew            #+#    #+#             */
/*   Updated: 2022/08/05 02:17:17 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_content(void *content)
{
	free(content);
}

void	ps_print_stack(void *content)
{
	ft_printf("%d ", *((int *)(content)));
}
