/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 08:42:03 by mattif            #+#    #+#             */
/*   Updated: 2022/05/15 17:08:14 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort5_2(t_stack *a, t_stack *b, int min)
{
	if (a->array[1] == min)
	{
		rrotat(a, "rra\n");
		rrotat(a, "rra\n");
		push_top(a, b, "pb\n");
	}
	if (a->array[0] == min)
	{
		rrotat(a, "rra\n");
		push_top(a, b, "pb\n");
	}
}

void	sort5(t_stack *a, t_stack *b)
{
	int	i ;
	int	min;

	i = -1;
	while (++i < 2)
	{
		min = get_min(a);
		if (a->array[a->top] == min)
			push_top(a, b, "pb\n");
		if (a->array[a->top - 1] == min)
		{
			swap(a, "sa\n");
			push_top(a, b, "pb\n");
		}
		if (a->array[2] == min)
		{
			rotat_stack(a, "ra\n");
			swap(a, "sa\n");
			push_top(a, b, "pb\n");
		}
		sort5_2(a, b, min);
	}
	sort3(a);
	push_top(b, a, "pa\n");
	push_top(b, a, "pa\n");
}

void	sort3(t_stack *stack)
{
	int	*arr;

	arr = stack->array;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		swap(stack, "sa\n");
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		rotat_stack(stack, "ra\n");
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		swap(stack, "sa\n");
		rotat_stack(stack, "ra\n");
	}
	else if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
	{
		swap(stack, "sa\n");
		rrotat(stack, "rra\n");
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
		rrotat(stack, "rra\n");
}

void	sort_2(t_stack *a)
{
	if (a->array[1] > a->array[0])
		swap(a, "sa\n");
}
