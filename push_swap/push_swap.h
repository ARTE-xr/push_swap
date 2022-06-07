/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:16:10 by mattif            #+#    #+#             */
/*   Updated: 2022/05/22 15:33:25 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct stack
{
	int	capacity;
	int	*array;
	int	top;
}	t_stack;

//  utils //

char		**args(int ac, char **av);
char		**push_in_t_stack(int ac, char **av, int *i);
long long	ft_atoi(const char *str);
int			ft_isdigit(int i);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			is_double(char **t);
char		**ft_split(const char *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *src);
void		ft_stcpy(t_stack *stack_a, t_stack *stack_s);
void		ft_swap(int *a, int *b);
void		*ft_calloc(size_t count, size_t size);
void		ft_free1(t_stack *a, t_stack *b);
void		ft_bzero(void *s, size_t n);
void		ft_putstr(char *s);
int			check_limits(char **arr);
char		*ft_read(char *s, int fd);
char		*get_next_line(int fd);
char		*ft_strchr(char *s, int c);
int			is_empty(t_stack *data);

// creating stack //

t_stack		*creat_stack(unsigned int capacity);

// actions //
void		push(t_stack *stck, int item);
int			pop(t_stack *stck);
void		rrotat(t_stack *stack, char *s);
void		rotat_stack(t_stack *stack, char *s);
void		push_top(t_stack *stack1, t_stack *stack2, char *s);
void		swap(t_stack *stack, char *s);
void		o_double(t_stack *a, t_stack *b, int n, char *s);

// sorting //

void		sort5(t_stack *a, t_stack *b);
void		sort3(t_stack *stack);
void		sort_2(t_stack *a);
int			*get_flags(int *t, t_stack **a);
int			get_head(t_stack **a, int i, int j);
void		from_a_to_b(t_stack **a, t_stack **b, int nmb);
int			*long_list(t_stack **a, int *x);
void		push_from_a_to_b(t_stack **a, t_stack **b);
void		sort_b_to_a(t_stack *a, t_stack *b);

// get functions //

int			get_min(t_stack *a);
int			get_min_index(int *arr, int size);
int			get_next_num(t_stack *a, int nb);
int			highest_value(int arr[], int size);
int			circle(t_stack **stack, int n);
int			is_sorted(t_stack *stack);
int			get_index_max(int arr[], int size, int n);
int			is_in_arr(int arr[], int n, int size);
int			get_index(t_stack *stack, int m);

#endif