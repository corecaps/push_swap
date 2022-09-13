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
	// TODO print error code
	exit(code);
}

int	main(int argc, char **argv)
{
	t_node *top_a;
	t_node *top_b;

	top_a = NULL;
	top_b = NULL;
	if (parser(argc, argv, top_a))
		ft_error(1);
	return (0);
}