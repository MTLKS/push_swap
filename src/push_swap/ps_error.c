/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:36:29 by maliew            #+#    #+#             */
/*   Updated: 2022/08/12 01:28:55 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_exiterror(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ps_checkdupe(t_list *stack)
{
	t_list	*i;
	t_list	*j;

	i = stack;
	while (i && i->next)
	{
		j = i->next;
		while (j)
		{
			if (*(int *)i->content == *(int *)j->content)
			{
				ft_lstclear(&stack, &ps_free_content);
				ps_exiterror();
			}
			j = j->next;
		}
		i = i->next;
	}
}

static void	ps_remove_leading_chars(char *str)
{
	int	i;
	int	plus;

	i = -1;
	plus = 0;
	while (ft_strchr("0 +\t", str[++i]) && str[i + 1])
	{
		if (str[i] == '+')
		{
			if (plus)
				return ;
			else
				plus = 1;
		}
		str[i] = ' ';
	}
}

int	ps_checkarr(char **arr)
{
	char	*a;
	char	*b;
	int		res;
	int		i;

	i = -1;
	while (arr[++i])
	{
		a = ft_itoa(ft_atoi(arr[i]));
		ps_remove_leading_chars(arr[i]);
		b = ft_strtrim(arr[i], " \t");
		res = (ft_strncmp(a, b, ft_strlen(a) + ft_strlen(b)) || !ft_strlen(b));
		if (ft_atoi(arr[i]) == 0 && !ft_strlen(b))
			res = 0;
		free(a);
		free(b);
		if (res)
			return (res);
	}
	return (i == 0);
}
