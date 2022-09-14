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
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
void	print_stack(t_node *top_a,t_node *top_b);
int		parser(int argc, char **argv, t_node **top_a);
t_node	*push(t_node *top, int n);
t_node	*push_bottom(t_node *top, int n);
t_node	*get_bottom(t_node *top);
int		pop(t_node **top);
t_result 	ft_atoi(const char *str);
#endif