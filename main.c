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
	ft_printf("Error");
	exit(code);
}

int	main(int argc, char **argv)
{
	t_node	*stacks[2];
//	t_chunk *initial_chunk;

	stacks[STACK_A] = NULL;
	stacks[STACK_B] = NULL;
	if (parser(argc, argv, stacks))
		ft_error(1);
//	initial_chunk = malloc (sizeof(t_chunk));
//	if (initial_chunk == NULL)
//		ft_error(1);
//	initial_chunk->stack = STACK_A;
//	initial_chunk->n = count_stack(stacks[STACK_A]);
//	test_3_sort();
	sort(stacks);
//	print_stack(stacks[STACK_A],stacks[STACK_B]);//	operations_test(&top_a, &top_b);
//	free(initial_chunk);
	clean_memory(stacks[STACK_A]);
	clean_memory(stacks[STACK_B]);
	return (0);
}