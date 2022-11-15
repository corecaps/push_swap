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

static int substr_parser(char *str, t_node **stacks)
{
	char		**args;
	int			pos;
	t_result 	result;

	args = ft_split(str,' ');
	pos = 0;
	while (args[pos] != NULL)
	{
		result = ft_atoi(args[pos]);
		if (result.err)
			return (1);
		else
		{
			*stacks = push_bottom(stacks[STACK_A], result.n);
			if (stacks[STACK_A] == NULL)
				return (1);
		}
			// TODO Error Handling
		pos ++;
	}
	return (0);
}

int	parser(int argc, char **argv, t_node **stacks)
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
			if (substr_parser(argv[pos], stacks))
				return (1);
			else
			{
				pos ++;
				continue;
			}
		}
		result = ft_atoi(argv[pos]);
		if (result.err == 0)
		{
			*stacks = push_bottom(stacks[STACK_A], result.n);
			if (*stacks == NULL)
				return (1);
		}
		// TODO Error handling
		else
			return (1);
		pos ++;
	}
	return (0);
}