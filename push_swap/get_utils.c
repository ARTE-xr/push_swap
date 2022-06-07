/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 08:55:37 by mattif            #+#    #+#             */
/*   Updated: 2022/05/12 18:31:49 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *a)
{
	int	min;
	int	i;

	min = a->array[0];
	i = 0;
	while (i <= a->top)
	{
		if (a->array[i] < min)
			min = a->array[i];
		i++;
	}
	return (min);
}

int	highest_value(int arr[], int size)
{
	int	i;
	int	max;

	i = 0;
	max = arr[0];
	while (i <= size)
	{
		if (max < arr[i])
			max = arr[i];
		i++;
	}
	return (max);
}

int	get_min_index(int *arr, int size)
{
	int	index;
	int	min;
	int	i;

	index = 0;
	min = arr[index];
	i = 0;
	while (i < size)
	{
		if (arr[i] <= min)
		{
			index = i;
			min = arr[index];
		}
		i++;
	}
	return (index);
}

int	get_next_num(t_stack *a, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (i <= a->top)
	{
		j = circle(&a, i);
		if (a->array[i] < nb && a->array[j] > nb)
			return (a->array[j]);
		i++;
	}
	return (get_min(a));
}

int	get_index_max(int arr[], int size, int n)
{
	int	i;

	i = size;
	while (i >= 0)
	{
		if (arr[i] == n)
			return (i);
		i--;
	}
	return (i);
}
