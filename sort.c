//
// Created by corecaps on 15/11/22.
//

#include <limits.h>
#include "push_swap.h"

int	is_sorted(t_node *stack, int n)
{
	int i;

	i = 0;
	if (stack == NULL)
		return (1);
	while (stack && i < n)
	{
		if (stack->next)
		{
			if (stack->next->n < stack->n)
				return (0);
		}
		stack = stack->next;
		n ++;
	}
	return (1);
}
int	find_median(t_node *stack, int n)
{
	int *array;
	int result;

	array  = stack_to_array(stack,n);
	result = get_pivot(array,0, n-1);
	free(array);
	return (result);
}
//void push_biggest(t_node **stacks, int n)
//{
//	int biggest;
//	int i;
//	t_node *pos;
//
//	pos = stacks[STACK_B];
//	i = 0;
//	biggest = peek(pos);
//	while (i < n)
//	{
//		if (biggest < peek(pos))
//			biggest = peek(pos);
//		i ++;
//		pos = pos->next;
//	}
//	i = 0;
//	while (peek(stacks[STACK_B]) != biggest)
//	{
//		rb(stacks);
//		i ++;
//	}
//	pa(stacks);
//	i --;
//	while (i > 0)
//	{
//		rrb(stacks);
//		i --;
//	}
//}

int sort(t_node **stacks)
{
	int	median;
	int	i;
	int j;
	int size;
	int ch_size;
	t_node *chunk;

	chunk = NULL;
	size = count_stack(stacks[STACK_A]);
	while (size > 2)
	{
		ch_size = 0;
		median = find_median(stacks[STACK_A], size);
		i = 0;
		while (i < size)
		{
			if (peek(stacks[STACK_A]) < median)
			{
				pb(stacks);
				ch_size ++;
			}
			else
				ra(stacks); // add rra if last on stacks is < median
			i ++;
		}
		chunk = push(chunk,ch_size);
//		print_stack(stacks[STACK_A],stacks[STACK_B]);
		// implement a break if is sorted stack a, size
		size = count_stack(stacks[STACK_A]);
	}
	if (peek(stacks[STACK_A]) > peek(stacks[STACK_A]->next))
		sa(stacks);
//	print_stack(stacks[STACK_A],stacks[STACK_B]);
	// push back
	// Make a recursive function
	// pushback when size <= 2
	// make a stack of chunk when moving
	while (chunk)
	{
//		print_stack(stacks[STACK_A],stacks[STACK_B]);
		size = pop(&chunk);
		if (count_stack(stacks[STACK_B]) < size)
			break ;
		if (size == 1)
			pa(stacks);
		else if (size == 2)
		{
			if (peek(stacks[STACK_B]) < peek(stacks[STACK_B]->next))
				sb(stacks);
			pa(stacks);
			pa(stacks);
		}
		else
		{
			while (count_stack(stacks[STACK_B]) > 2)
			{
				ch_size = 0;
//				print_stack(stacks[STACK_A], stacks[STACK_B]);
				median = find_median(stacks[STACK_B], size);
				i = 0;
				while (i < size)
				{
					if (peek(stacks[STACK_B]) > median)
					{
						j = 0;
						while (peek(stacks[STACK_A])<peek(stacks[STACK_B]))
						{
							ra(stacks);
							j ++;
						}
						pa(stacks);
						while (j > 0)
						{
							rra(stacks);
							j --;
						}
						ch_size++;
					}
					else
						rb(stacks);
					i++;
				}
			}

			if (chunk)
			{
				i = 0;
				while (i++ < (size - ch_size))
					rb(stacks);
			}
			if (ch_size > 0)
				chunk = push(chunk,size - ch_size);
		}
//		print_stack(stacks[STACK_A],stacks[STACK_B]);
	}
	return (0);
}