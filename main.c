/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:09:22 by jgarcia           #+#    #+#             */
/*   Updated: 2022/09/01 11:12:44 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int code)
{
	ft_printf("Parsing Error");
	exit(code);
}

int	main(int argc, char **argv)
{
	t_node	*top_a;
	t_node	*top_b;
	t_chunk *initial_chunk;

	top_a = NULL;
	top_b = NULL;
	if (parser(argc, argv, &top_a))
		ft_error(1);
	initial_chunk = malloc (sizeof(t_chunk));
	if (initial_chunk == NULL)
		ft_error(1);
	initial_chunk->stack = top_a;
	initial_chunk->n = count_stack(top_a);
	sort(*initial_chunk,&top_a,&top_b);
	//	operations_test(&top_a, &top_b);
	free(initial_chunk);
	clean_memory(top_a);
	clean_memory(top_b);
	return (0);
}