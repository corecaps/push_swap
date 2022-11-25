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

int	main(int argc, char **argv)
{
	t_node	*stacks[2];

	stacks[STACK_A] = NULL;
	stacks[STACK_B] = NULL;
	if (parser(argc, argv, stacks))
	{
		ft_printf("Error");
		return(-1);
	}
	sort(stacks);
	clean_memory(stacks[STACK_A]);
	clean_memory(stacks[STACK_B]);
	return (0);
}