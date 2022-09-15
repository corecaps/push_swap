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
	t_node *top_a;
	t_node *top_b;

	top_a = NULL;
	top_b = NULL;
	(void) top_b;
	if (parser(argc, argv, &top_a))
		ft_error(1);
	print_stack(top_a,top_b);
	ft_printf("numbers in stack a: %d\n", count_stack(top_a));
	ft_printf("numbers in stack b: %d\n", count_stack(top_b));
	operations_test(&top_a, &top_b);
	return (0);
}