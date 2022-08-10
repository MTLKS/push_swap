/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_range_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:57:16 by maliew            #+#    #+#             */
/*   Updated: 2022/08/10 20:46:35 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ps_range_new(int min, int max)
{
	int	*range;

	range = (int *)malloc(2 * sizeof(int));
	range[0] = min;
	range[1] = max;
	return (range);
}

int	ps_range_get(t_list *range, int max)
{
	return (((int *)range->content)[max]);
}
