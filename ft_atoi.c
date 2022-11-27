/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:33:11 by jgarcia           #+#    #+#             */
/*   Updated: 2022/05/23 14:13:36 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

static long check_result(long int result)
{
	if (result > INT_MAX || result < INT_MIN)
	{
			return (-1);
	}
	return (0);
}
static int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_result 	ft_atoi(const char *str)
{
	int	signe;
	int	pos;
	t_result	res;
	long int	result;

	signe = 1;
	result = 0;
	if (str[0] == '-')
	{
		signe *= -1;
		str ++;
	}
	else if (str[0] == '+')
		str ++;
	pos = 0;
	while ((str[pos] != '\0'))
	{
		if (!ft_isdigit(str[pos]))
		{
			res.err = 1;
			return (res);
		}
		result = result * 10 + str[pos] - '0';
		pos ++;
	}
	if (ft_isdigit(str[pos]))
	{
		res.err = 1;
		return (res);
	}
	result *= signe;
	res.err = check_result(result);
	res.n = (int)result;
	return (res);
}