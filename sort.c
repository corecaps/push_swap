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

void push_opposite(t_node **stacks,t_stack s_idx)
{
	if (s_idx == STACK_A)
		pb(stacks);
	else
		pa(stacks);
}

void push_back(t_node **stacks,t_stack s_idx,t_node *chunk)
{
	int median;
	int ch_size;
	int size;
	int i;
	t_node *new_chunk;

	new_chunk = NULL;
	while (chunk)
	{
		size = pop(&chunk);
		if (size < 1)
			return;
		else if (size == 1)
			push_opposite(stacks,s_idx);
		else if (size == 2)
		{
			if (s_idx == STACK_A)
			{
				// refactor without the branching
				// implement is_sorted with inverse order
				if (peek(stacks[s_idx]) > (peek(stacks[s_idx]->next)))
					sa(stacks);
				pb(stacks);
				pb(stacks);
			}
			else
			{
				if (peek(stacks[s_idx]) < (peek(stacks[s_idx]->next)))
					sb(stacks);
				pa(stacks);
				pa(stacks);
			}
		}
		else
		{
			// if sorted push opposite
			// else :
			ch_size = 0;
			i = 0;
			// find median
			median = find_median(stacks[s_idx],size);
			while (i < size)
			{
				// push to opposite side everything above or greater
				// than median depending on stack
				if (s_idx == STACK_A)
				{
					if (peek(stacks[s_idx]) < median)
					{
						ch_size ++;
						pb(stacks);
					}
					else
					{
						ra(stacks);
					}
					i ++;
				}
				else
				{
					if (peek(stacks[s_idx]) > median)
					{
						ch_size ++;
						pa(stacks);
					}
					else
					{
						rb(stacks);
					}
					i ++;
				}
			}
			if (ch_size == 1)
			{
				if (s_idx == STACK_A)
				{
					if (peek(stacks[STACK_B]) > peek(stacks[STACK_B]->next))
						sb(stacks);
					pa(stacks);
					pa(stacks);
				}
				else
				{
					if (peek(stacks[STACK_A]) > peek(stacks[STACK_A]->next))
						sa(stacks);
					pb(stacks);
					pb(stacks);
				}

			}
			else if (ch_size > 2)
			{
				// create a new chunk stack to process the recursive call
				new_chunk = push(new_chunk, ch_size);
				// recursive call to push_back if more than 2 push
				push_back(stacks, !s_idx, new_chunk);
			}
			// if == 2 push check order and swap if necessary
			// if not last chunk
			if (chunk)
			{
				i = 0;
				while (i++ < (size - ch_size))
				{
					if (s_idx == STACK_A)
						rra(stacks);
					else
						rrb(stacks);
				}
			}
			if (size - ch_size > 0)
				chunk = push(chunk,size - ch_size);
		}
	}
}

int sort(t_node **stacks){
	int	median;
	int	i;
//	int j;
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
	push_back(stacks,STACK_B,chunk);
	//	print_stack(stacks[STACK_A],stacks[STACK_B]);
	// push back
	// Make a recursive function
	// pushback when size <= 2
	// make a stack of chunk when moving
//	while (chunk)
//	{
////		print_stack(stacks[STACK_A],stacks[STACK_B]);
//		size = pop(&chunk);
//		if (count_stack(stacks[STACK_B]) < size)
//			break ;
//		if (size == 1)
//			pa(stacks);
//		else if (size == 2)
//		{
//			if (peek(stacks[STACK_B]) < peek(stacks[STACK_B]->next))
//				sb(stacks);
//			pa(stacks);
//			pa(stacks);
//		}
//		else
//		{
//			while (count_stack(stacks[STACK_B]) > 2)
//			{
//				ch_size = 0;
////				print_stack(stacks[STACK_A], stacks[STACK_B]);
//				median = find_median(stacks[STACK_B], size);
//				i = 0;
//				while (i < size)
//				{
//					if (peek(stacks[STACK_B]) > median)
//					{
//						j = 0;
//						while (peek(stacks[STACK_A])<peek(stacks[STACK_B]))
//						{
//							ra(stacks);
//							j ++;
//						}
//						pa(stacks);
//						while (j > 0)
//						{
//							rra(stacks);
//							j --;
//						}
//						ch_size++;
//					}
//					else
//						rb(stacks);
//					i++;
//				}
//			}
//
//			if (chunk)
//			{
//				i = 0;
//				while (i++ < (size - ch_size))
//					rb(stacks);
//			}
//			if (ch_size > 0)
//				chunk = push(chunk,size - ch_size);
//		}
////		print_stack(stacks[STACK_A],stacks[STACK_B]);
//	}
	return (0);
}