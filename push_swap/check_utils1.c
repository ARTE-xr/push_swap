/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:30:34 by mattif            #+#    #+#             */
/*   Updated: 2022/05/15 18:11:10 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	int				i;
	int				n;
	long long		res;

	i = 0;
	res = 0;
	n = 1;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		||str[i] == '\f' || str[i] == '\v' || str[i] == ' ' )
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * n);
}

int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	else
		return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			a;
	int			i;
	char		*s;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	s = (char *)malloc(a + ft_strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s[a] = s2[i];
		a++;
		i++;
	}
	s[a] = '\0';
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_double(char **t)
{
	int	i;
	int	j;

	i = 0;
	while (t[i])
	{
		j = i + 1;
		while (t[j])
		{
			if (ft_atoi(t[i]) == ft_atoi(t[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
