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
typedef struct s_node
{
	int n;
	struct s_node *next;
}t_node;
int		parser(int argc,char **argv,t_node *top_a,t_node *top_b);
t_node	*push(t_node *top, int n);
t_node	*get_bottom(t_node *top);
int		pop(t_node **top);
#endif