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
typedef enum e_stack
{
	STACK_A,
	STACK_B
} t_stack;
typedef enum e_3_pos
{
	MIN_TOP = 1,
	MIN_MIDDLE = 2,
	MIN_BOTTOM = 4,
	MAX_TOP = 8,
	MAX_MIDDLE = 16,
	MAX_BOTTOM = 32
} t_3_pos;
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
typedef struct s_chunk
{
	t_stack	stack;
	int		n;
	int 	current_pivot;
}t_chunk;
typedef struct s_partition
{
	t_chunk	high_chunk;
	t_chunk	low_chunk;
} t_partition;
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strdup(char *src);
void		*ft_memcpy(void *dest, const void *src, size_t n);
t_result 	ft_atoi(const char *str);
char		**ft_split(const char *s, char c);
int			parser(int argc, char **argv, t_node **stacks);
t_node		*push(t_node *top, int n);
t_node		*push_bottom(t_node *top, int n);
t_node		*get_bottom(t_node *top);
int			pop(t_node **top);
int			pop_bottom(t_node **top);
int			is_in_stack(t_node *top_a,int n);
int			count_stack(t_node *top);
int			peek(t_node *top);
int 		*stack_to_array(t_node *stack, int n);
void		sort_array(int *array,int start,int end);
int			get_pivot(int *array,int start,int end);
int			sa(t_node **stacks);
int			sb(t_node **stacks);
int			ss(t_node **stacks);
int			pa(t_node **stacks);
int			pb(t_node **stacks);
int			ra(t_node **stacks);
int			rb(t_node **stacks);
int			rr(t_node **stacks);
int			rra(t_node **stacks);
int			rrb(t_node **stacks);
int			rrr(t_node **stacks);
//debug
void		print_stack(t_node *top_a,t_node *top_b);
void		print_chunk(t_chunk chunk,t_node *top_a,t_node *top_b);
void		operations_test(t_node **top_a, t_node **top_b);
int			bottom_up_merge_sort(t_node **top_a, t_node **top_b);
void		sort_3(t_node **stacks,t_stack s_idx);
void		test_3_sort();
//end debug
void		clean_memory(t_node *stack);
void sort(t_node **stacks);
t_node *first_split(t_node **stacks, int size, t_node *chunk);
#endif