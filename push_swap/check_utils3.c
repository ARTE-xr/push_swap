/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:19:19 by mattif            #+#    #+#             */
/*   Updated: 2022/05/18 16:18:30 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	while (src[i] != '\0')
		i++;
	len = i;
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	check_limits(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_atoi(arr[i]) < -2147483648 || ft_atoi(arr[i]) > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}
