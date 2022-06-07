/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:41:53 by mattif            #+#    #+#             */
/*   Updated: 2022/05/15 18:41:56 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *s)
{
	if (stack->top == 0 || stack->top == -1)
		return ;
	ft_swap(&stack->array[stack->top], &stack->array[stack->top - 1]);
	if (!s)
		return ;
	ft_putstr(s);
}

void	push_top(t_stack *stack1, t_stack *stack2, char *s)
{
	if (stack1->top == -1)
		return ;
	stack2->array[++stack2->top] = stack1->array[stack1->top--];
	if (!s)
		return ;
	ft_putstr(s);
}

void	rotat_stack(t_stack *stack, char *s)
{
	int	tmp ;
	int	i;

	tmp = stack->array[stack->top];
	i = stack->top + 1;
	while (--i)
	{
		stack->array[i] = stack->array[i - 1];
	}
	stack->array[0] = tmp;
	if (!s)
		return ;
	ft_putstr(s);
}

void	rrotat(t_stack *stack, char *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->array[0];
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->top] = tmp;
	if (!s)
		return ;
	ft_putstr(s);
}

void	o_double(t_stack *a, t_stack *b, int n, char *s)
{
	if (n == 1)
	{
		rrotat(a, 0);
		rrotat(b, 0);
	}
	else if (n == 2)
	{
		rotat_stack(a, 0);
		rotat_stack(b, 0);
	}
	else if (n == 3)
	{
		swap(a, 0);
		swap(b, 0);
	}
	if (!s)
		return ;
	ft_putstr(s);
}
