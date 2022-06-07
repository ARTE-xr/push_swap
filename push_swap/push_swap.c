/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 04:01:15 by mattif            #+#    #+#             */
/*   Updated: 2022/05/15 17:24:34 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**tab;
	int		i;
	int		count;
	t_stack	*a;
	t_stack	*b;

	tab = push_in_t_stack(ac, av, &i);
	count = i;
	a = creat_stack(i);
	b = creat_stack(i);
	i = i - 1;
	while (i >= 0)
		push(a, ft_atoi(tab[i--]));
	if (count == 1)
		exit(1);
	else if (count == 2)
		sort_2(a);
	else if (count == 3)
		sort3(a);
	else if (count == 5)
		sort5(a, b);
	else
		push_from_a_to_b(&a, &b);
	sort_b_to_a(a, b);
	ft_free1(a, b);
}
