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
	int size;
	int i;
	int sw;
	int side;
	int j;
	int k;
	int l;
	int m;

	size = count_stack(*top_a);
	i = 0;
	sw = 0;
	side = 1;
	while (i < size / 2)
	{
//		if ((*top_a)->n < ((*top_a)->next->n))
//			sa(top_a);
		if (sw == 0)
		{
			if ((*top_a)->n < ((*top_a)->next->n))
				sa(top_a);
			pb(top_a, top_b);
			pb(top_a, top_b);
			sw = 1;
		}
		else
		{
			if ((*top_a)->n > ((*top_a)->next->n))
				sa(top_a);
			ra(top_a);
			ra(top_a);
			sw = 0;
		}
		i ++;
	}
	m = 4;
	while (m <= size )
	{
		i = 0;
		while (i < size / m)
		{
			j = 0;
			k = 0;
			l = 0;
			if (side == 0)
			{
				while (j < m)
				{
					if (((*top_b)->n > (*top_a)->n && l < (m/2)) || (k == (m/2)))
					{
						pb(top_a, top_b);
						l++;
					}
					else
					{
						k++;
					}
					rb(top_b);
					j++;
				}
				side = 1;
			}
			else
			{
				while (j < m)
				{
					if (((*top_a)->n > (*top_b)->n && l < (m/2)) || (k == (m/2)))
					{
						pa(top_a, top_b);
						l++;
					}
					else
					{
						k++;
					}
					ra(top_a);
					j++;
				}
				side = 0;
			}
			i++;
		}
		m *= 2;
	}

/*	int *array;
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
	//ft_printf("pivot :\t%d\n",pivot);
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
	//print_stack(*top_a,*top_b);
	while (j > 0)
	{
		pa(top_a,top_b);
		j--;
	}
//	if (is_sorted(*top_a))
//		ft_printf("sorted\n");
//	else
//		ft_printf("not sorted\n");
	free (array);
	*/
	return (0);
}