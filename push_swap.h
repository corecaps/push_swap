/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:11:02 by jgarcia           #+#    #+#             */
/*   Updated: 2022/09/01 11:12:10 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
typedef struct s_node
{
	int n;
	struct s_node *next;
}t_node;
typedef struct s_result
{
	int n;
	int err;
} t_result;
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strdup(char *src);
void		*ft_memcpy(void *dest, const void *src, size_t n);
t_result 	ft_atoi(const char *str);
char		**ft_split(const char *s, char c);
void		operations_test(t_node **top_a, t_node **top_b);
int			parser(int argc, char **argv, t_node **top_a);
t_node		*push(t_node *top, int n);
t_node		*push_bottom(t_node *top, int n);
t_node		*get_bottom(t_node *top);
int			pop(t_node **top);
int			pop_bottom(t_node **top);
int			is_in_stack(t_node *top_a,int n);
int			count_stack(t_node *top);
int			*stack_to_array(t_node *stack);
void		sort_array(int *array,int start,int end);
int			get_pivot(int *array,int start,int end);
int			sa(t_node **top_a);
int			sb(t_node **top_b);
int			ss(t_node **top_a,t_node **top_b);
int			pb(t_node **top_a,t_node **top_b);
int			pa(t_node **top_a,t_node **top_b);
int			ra(t_node **top_a);
int			rb(t_node **top_b);
int			rr(t_node **top_a,t_node **top_b);
int			rra(t_node **top_a);
int			rrb(t_node **top_b);
int			rrr(t_node **top_a,t_node **top_b);
void		print_stack(t_node *top_a,t_node *top_b);
#endif