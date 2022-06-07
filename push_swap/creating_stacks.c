/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:21:10 by mattif            #+#    #+#             */
/*   Updated: 2022/05/25 13:25:19 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*creat_stack(unsigned int capacity)
{
	t_stack	*stck;

	stck = malloc(sizeof(t_stack));
	stck->capacity = capacity;
	stck->top = -1;
	stck->array = malloc(stck->capacity * sizeof(int));
	return (stck);
}

void	push(t_stack *data, int item)
{
	if (data->top == data->capacity - 1)
		return ;
	data->array[++data->top] = item;
}

void	pb(t_stack *stck1, t_stack *stck2, int pid)
{
	if (stck1->top == -1)
		return ;
	stck2->array[++stck2->top] = stck1->array[stck1->top--];
	if (pid)
		write(1, "pb\n", 3);
}

int	is_empty(t_stack *data)
{
	return (data->top == -1);
}
