/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_up_merge_sort.c                             :+:      :+:    :+:   */
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

int	bottom_up_merge_sort(t_node **top_a, t_node **top_b)
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
t_partition stack_partition(t_chunk current_chunk, t_node **top_a, t_node **top_b)
{
	t_partition res;
	t_node **current_stack;
	int i;

	if (current_chunk.stack == STACK_A)
		current_stack = top_a;
	else if (current_chunk.stack == STACK_B)
		current_stack = top_b;
	res.low_chunk.n = (current_chunk.n / 2)  - 1;
	res.high_chunk.n = (current_chunk.n / 2) + (current_chunk.n % 2);
	i = 0;
	if (current_chunk.n <= 1 || current_chunk.stack < 0 || current_chunk.stack > STACK_B)
	{
		res.high_chunk.n = -1;
		res.low_chunk.n = -1;
		return (res);
	}
	while (i < current_chunk.n && *current_stack)
	{
		// TODO : invert condition to shorten code
		ft_printf("N:%d\tPivot:%d\n",peek(*current_stack),current_chunk.current_pivot);
		if (current_chunk.stack == STACK_A)
		{
			if (peek(*current_stack) > current_chunk.current_pivot)
				pb(top_a,top_b);
			else if (peek(*current_stack) == current_chunk.current_pivot)
			{
				if (i == current_chunk.n - 1)
					break ;
				sa(top_a);
				i --;
			}
			else
				ra(top_a);
		}
		else
		{
			if (peek(*current_stack) < current_chunk.current_pivot)
				pa(top_a,top_b);
			else if (peek(*current_stack) == current_chunk.current_pivot)
			{
				if (i == current_chunk.n - 1)
					break ;
				sb(top_b);
				i --;
			}
			else
				rb(top_b);
		}
		i ++;
	}
	if (current_chunk.stack == STACK_A) //sens 0 : top_a 1: top_b
		ra(top_a);
	else
		rb(top_b);
	if (current_chunk.stack == STACK_B) { //sens 0 : top_a 1: top_b
		res.high_chunk.stack = STACK_A;
		res.low_chunk.stack = STACK_B;
	} else {
		res.high_chunk.stack = STACK_B;
		res.low_chunk.stack = STACK_A;
	}
	return (res);
}


#include <stdio.h>
void print_chunk(t_chunk chunk,t_node *top_a,t_node *top_b)
{
	t_node *pos;
	if (chunk.stack < STACK_A || chunk.stack > STACK_B)
		return ;
	if (chunk.stack == STACK_A)
		pos = top_a;
	else
		pos = top_b;
	int n = chunk.n;
	int i = 0;
	printf("A:\t %p\tB:\t %p\tCurrent chunk :\t stack: %p\t n:%d\n",top_a,top_b,pos,n);
	while (i < n) {
		printf("%d\n",pos->n);
		pos = pos->next;
		i ++;
	}
}
void push_back(t_chunk current,t_node **top_a, t_node **top_b)
{
	int i;

	i = 0;
	print_stack(*top_a,*top_b);
	while (i < current.n)
	{
		if (current.stack == STACK_A)
		{
			pb(top_a,top_b);
		}
		else
		{
			pa(top_a,top_b);
		}
		i ++;
	}
//	if (current.stack == STACK_A)
//		rra(top_a);
//	else
//		rrb(top_b);
	print_stack(*top_a,*top_b);
}
int sort(t_chunk current_chunk, t_node **top_a, t_node **top_b)
{
	int *array;
	t_partition result;

	if (current_chunk.n == 2)
	{
//		if (current_chunk.stack == STACK_A)
//		{
//			if (peek(*top_a)  > peek((*top_a)->next))
//				sa(top_a);
//		}
//		else
//		{
//			if (peek(*top_b) < peek((*top_b)->next))
//				sb(top_b);
//		}
		return (1);
	}
	else if (current_chunk.n <= 1)
		return (1);
	if (current_chunk.stack == STACK_A)
		array = stack_to_array(*top_a,current_chunk.n);
	else
		array = stack_to_array(*top_b,current_chunk.n);
	current_chunk.current_pivot = get_pivot(array,0, current_chunk.n-1);
	ft_printf("pivot :\t%d\n",current_chunk.current_pivot);
	print_stack(*top_a,*top_b);
	print_chunk(current_chunk,*top_a,*top_b);
	result = stack_partition(current_chunk,top_a,top_b);
	print_stack(*top_a,*top_b);

	if (sort(result.low_chunk,top_a,top_b) == 0)
		push_back(result.low_chunk,top_a,top_b);

	print_stack(*top_a,*top_b);
	sort(result.high_chunk,top_a,top_b);
//	result.high_chunk.n --;
//	push_back(result.high_chunk,top_a,top_b);
	// push_back
		print_stack(*top_a,*top_b);
	print_stack(*top_a,*top_b);
	if (is_sorted(*top_a))
		ft_printf("sorted\n");
	else
		ft_printf("not sorted\n");

	free (array);
	return (0);
}