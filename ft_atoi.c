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

static long int	check_result(long int result, int signe)
{
	if (result > INT_MAX || result < INT_MIN)
	{
		if (signe < 1)
			return (0);
		else
			return (-1);
	}
	return (result);
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
	while ((str[pos] != '\0') && (ft_isdigit(str[pos])))
	{
		result = result * 10 + str[pos] - '0';
		pos ++;
	}
	if (ft_isdigit(str[pos]) == 0)
	{
		res.err = 1;
		res.n = 0;
		return (res);
	}
	result *= signe;
	result = check_result(result, signe);
	res.n = (int)result;
	res.err = 0;
	return (res);
}