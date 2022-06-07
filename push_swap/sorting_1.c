/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:25:40 by mattif            #+#    #+#             */
/*   Updated: 2022/05/15 18:42:12 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_flags(int *t, t_stack **a)
{
	int	*flag;
	int	k;
	int	l;
	int	j;
	int	i;

	flag = (int *)ft_calloc(highest_value(t, (*a)->top), sizeof(int));
	if (!flag)
		exit (1);
	i = get_index_max(t, (*a)->top, highest_value(t, (*a)->top));
	j = circle(a, i);
	k = i;
	l = 0;
	while (j != i)
	{
		if ((*a)->array[j] > (*a)->array[k])
		{
			flag[l] = (*a)->array[k];
			l++;
			k = j;
		}
		j = circle(a, j);
	}
	flag[l] = (*a)->array[k];
	return (flag);
}

int	get_head(t_stack **a, int i, int j)
{
	int	k;
	int	count;

	count = 1;
	k = i;
	while (j != i)
	{
		if ((*a)->array[j] > (*a)->array[k])
		{
			count++;
			k = j;
		}
		j = circle(a, j);
	}
	return (count);
}

int	*the_long_list(t_stack **a, int *p)
{
	int	i;
	int	j;
	int	*t;
	int	*flag;

	t = (int *)ft_calloc((*a)->top + 1, sizeof(int));
	if (!t)
		exit (1);
	i = (*a)->top;
	j = circle(a, i);
	while (i)
	{
		t[i] = get_head(a, i, j);
		i--;
		j = circle(a, i);
	}
	flag = get_flags(t, a);
	*p = highest_value(t, (*a)->top);
	free(t);
	return (flag);
}

void	push_from_a_to_b(t_stack **a, t_stack **b)
{
	int	i;
	int	*flag;
	int	m;
	int	next;

	flag = the_long_list(a, &m);
	i = (*a)->top;
	while (i >= 0)
	{
		if (!is_in_arr(flag, (*a)->array[i], m))
		{
			next = (*a)->array[circle(a, i)];
			from_a_to_b(a, b, (*a)->array[i]);
			i = get_index(*a, next);
			i++;
		}
		i--;
	}
	free(flag);
}
