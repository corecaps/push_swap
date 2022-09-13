/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:57:11 by jgarcia           #+#    #+#             */
/*   Updated: 2022/09/01 17:57:39 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int space_in_string(char *str)
{
	while (*str != '\0')
	{
		if (*str == ' ')
			return (1);
		str ++;
	}
	return (0);
}

static int substr_parser(char *str, t_node *top_a)
{

	return (0);
}

int	parser(int argc,char **argv,t_node *top_a)
{
	int pos;
	t_result result;

	if (argc <= 1)
		return (1);
	pos = 1;
	while (pos < argc)
	{
		if (space_in_string(argv[pos]))
		{
			if (substr_parser(argv[pos], top_a))
				return (1);
		}
		result = ft_atoi(argv[pos]);
		if (result.err == 0)
			push(top_a,result.n);
		else
			return (1);
		pos ++;
	}
}