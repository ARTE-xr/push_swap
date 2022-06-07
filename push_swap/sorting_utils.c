/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:28:48 by mattif            #+#    #+#             */
/*   Updated: 2022/05/25 13:25:35 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	circle(t_stack **stack, int n)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if (n > 0)
			n--;
		else
			n = (*stack)->top;
		i++;
	}
	return (n);
}

int	is_in_arr(int arr[], int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (1);
		i++;
	}
	return (0);
}

void	from_a_to_b(t_stack **a, t_stack **b, int nmb)
{
	while (nmb != (*a)->array[(*a)->top])
	{
		rotat_stack(*a, "ra\n");
	}
	push_top(*a, *b, "pb\n");
}

int	is_sorted(t_stack *stack)
{
	int	i;
	int	nb;

	i = 0;
	nb = stack->array[i];
	while (i <= stack->top)
	{
		if (nb < stack->array[i])
			return (0);
		nb = stack->array[i];
		i++;
	}
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned int	total;

	total = count * size;
	ptr = (void *)malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
