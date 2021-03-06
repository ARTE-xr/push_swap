/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:58:15 by mattif            #+#    #+#             */
/*   Updated: 2022/05/22 15:25:39 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_p(t_stack *a, t_stack *b, int nb, int next_nb)
{
	int	index;
	int	next_nb_index;
	int	arr[3];

	index = get_index(b, nb);
	next_nb_index = get_index(a, next_nb);
	if (index >= b->top / 2)
		arr[0] = b->top - index;
	else
		arr[0] = index + 1;
	if (next_nb_index >= a->top / 2)
		arr[0] += a->top - next_nb_index;
	else
		arr[0] += next_nb_index + 1;
	if (index + 1 > next_nb_index + 1)
		arr[1] = index + 1;
	else
		arr[1] = next_nb_index + 1;
	if (b->top - index > a->top - next_nb_index)
		arr[2] = b->top - index;
	else
		arr[2] = a->top - next_nb_index;
	return (get_min_index(arr, 3));
}

static	int	best_nb(t_stack *a, t_stack *b, int nb, int next_nb)
{
	int	index;
	int	next_nb_index;
	int	arr[3];

	index = get_index(b, nb);
	next_nb_index = get_index(a, next_nb);
	if (index >= b->top / 2)
		arr[0] = b->top - index;
	else
		arr[0] = index + 1;
	if (next_nb_index >= a->top / 2)
		arr[0] += a->top - next_nb_index;
	else
		arr[0] += next_nb_index + 1;
	if (index + 1 > next_nb_index + 1)
		arr[1] = index + 1;
	else
		arr[1] = next_nb_index + 1;
	if (b->top - index > a->top - next_nb_index)
		arr[2] = b->top - index;
	else
		arr[2] = a->top - next_nb_index;
	return (arr[get_min_index(arr, 3)]);
}

static	int	nb_stack(t_stack *a, t_stack *b)
{
	int	*count;
	int	comp;
	int	next_nb;
	int	i;

	count = (int *)ft_calloc(b->top + 1, sizeof(int));
	if (!count)
		exit (1);
	comp = 0;
	i = 0;
	while (i < b->top + 1)
	{
		next_nb = get_next_num(a, b->array[i]);
		count[i] = best_nb(a, b, b->array[i], next_nb);
		if (count[i] <= count[comp])
			comp = i;
		i++;
	}
	free (count);
	return (b->array[comp]);
}

static	void	push_to_stack_a(t_stack *a, t_stack *b, int nb, int next_nb)
{
	int	p;

	p = get_p(a, b, nb, next_nb);
	if (p == 1)
		while (a->array[a->top] != next_nb && b->array[b->top] != nb)
			o_double(a, b, 1, "rrr\n");
	else if (p == 2)
		while (a->array[a->top] != next_nb && b->array[b->top] != nb)
			o_double(a, b, 2, "rr\n");
	while (a->array[a->top] != next_nb)
	{
		if (get_index(a, next_nb) >= (a->top / 2))
			rotat_stack(a, "ra\n");
		else
			rrotat(a, "rra\n");
	}
	while (b->array[b->top] != nb)
	{
		if (get_index(b, nb) >= (b->top / 2))
			rotat_stack(b, "rb\n");
		else
			rrotat(b, "rrb\n");
	}
	push_top(b, a, "pa\n");
}

void	sort_b_to_a(t_stack *a, t_stack *b)
{
	int	nb;
	int	next_nb;
	int	min;

	while (b->top >= 0)
	{
		nb = nb_stack(a, b);
		next_nb = get_next_num(a, nb);
		push_to_stack_a(a, b, nb, next_nb);
	}
	min = get_min(a);
	while (a->array[a->top] != min)
	{
		if (get_index(a, min) >= (a->top) - (a->top / 2))
			rotat_stack(a, "ra\n");
		else
			rrotat(a, "rra\n");
	}
}
