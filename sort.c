/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:24:08 by jgarcia           #+#    #+#             */
/*   Updated: 2022/10/19 10:24:15 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *top)
{
	if (top == NULL)
		return (1);
	while (top)
	{
		if (top->next)
		{
			if (top->next->n < top->n)
				return (0);
		}
		top = top->next;
	}
	return (1);
}

int	sort(t_node **top_a,t_node **top_b)
{
	int *array;
	int size;
	int pivot;
	int i;
	int j;
	t_node *pos;
	t_node *tmp;
	size = count_stack(*top_a);
	array = stack_to_array(*top_a,size);
	pivot = get_pivot(array,0, size-1);
	pos = *top_a;
	i = 0;
	j = 0;
	ft_printf("pivot :\t%d\n",pivot);
	while (i < size)
	{
		tmp = pos->next;
		if (pos->n > pivot)
			pb(top_a,top_b);
		else if (pos->n == pivot)
		{
			pb(top_a,top_b);
			rb(top_b);
		}
		else
			ra(top_a);
		pos = tmp;
		i ++;
		j ++;
	}
	print_stack(*top_a,*top_b);
	while (j > 0)
	{
		pa(top_a,top_b);
		j--;
	}
/*	if (is_sorted(*top_a))
		ft_printf("sorted\n");
	else
		ft_printf("not sorted\n"); */
	free (array);
	return (0);
}
