//
// Created by corecaps on 15/11/22.
//

#include "push_swap.h"

int get_3_pos(t_node **stacks, t_stack s_idx)
{
	int result;
	int max;
	int min;
	int i;
	t_node *pos;

	pos = stacks[s_idx];
	max = peek(pos);
	min = peek(pos);
	i = 0;
	result = 0;
	while (i < 3)
	{
		if (peek(pos) > max)
			max = peek(pos);
		if (peek(pos) < min)
			min = peek(pos);
		pos = pos->next;
		i ++;
	}
	pos = stacks[s_idx];
	i = 0;
	while (i < 3)
	{
		if (peek(pos) == max)
			result += MAX_TOP << i;
		if (peek(pos) == min)
			result += MIN_TOP << i;
		i++;
		pos = pos->next;
	}
	return result;
}

void sort_3(t_node **stacks,t_stack s_idx)
{
	int pos_3;

	pos_3 = get_3_pos(stacks,s_idx);
	if (pos_3 == MIN_TOP + MAX_BOTTOM)
		return;
	else if (pos_3 == MIN_TOP + MAX_MIDDLE)
	{
		ra(stacks);
		sa(stacks);
		rra(stacks);

	}
	else if (pos_3 == MIN_MIDDLE + MAX_BOTTOM)
		sa(stacks);
	else if (pos_3 == MAX_MIDDLE + MIN_BOTTOM)
	{
		ra(stacks);
		sa(stacks);
		rra(stacks);
		sa(stacks);
	}
	else if (pos_3 == MAX_TOP + MIN_MIDDLE)
	{
		sa(stacks);
		ra(stacks);
		sa(stacks);
		rra(stacks);
	}
	else if (pos_3 == MAX_TOP + MIN_BOTTOM)
	{
		sa(stacks);
		ra(stacks);
		sa(stacks);
		rra(stacks);
		sa(stacks);
	}
}

void sort_3_A(t_node **stacks,t_stack s_idx)
{
	int pos_3;

	pos_3 = get_3_pos(stacks,s_idx);
	if (pos_3 == MIN_TOP + MAX_BOTTOM)
		return;
	else if (pos_3 == MIN_TOP + MAX_MIDDLE)
	{
		rra(stacks);
		sa(stacks);
	}
	else if (pos_3 == MIN_MIDDLE + MAX_BOTTOM)
		sa(stacks);
	else if (pos_3 == MAX_MIDDLE + MIN_BOTTOM)
		rra(stacks);
	else if (pos_3 == MAX_TOP + MIN_MIDDLE)
		ra(stacks);
	else if (pos_3 == MAX_TOP + MIN_BOTTOM)
	{
		sa(stacks);
		rra(stacks);
	}
}

void sort_3_reversed(t_node **stacks,t_stack s_idx)
{
	t_3_pos pos_3;

	pos_3 = get_3_pos(stacks,s_idx);
	if (pos_3 == MAX_TOP + MIN_BOTTOM)
		return;
	else if (pos_3 == MAX_TOP + MIN_MIDDLE)
	{
		rb(stacks);
		sb(stacks);
		rrb(stacks);
	}
	else if (pos_3 == MAX_MIDDLE + MIN_BOTTOM)
		sb(stacks);
	else if (pos_3 == MAX_BOTTOM + MIN_MIDDLE)
	{
		rb(stacks);
		sb(stacks);
		rrb(stacks);
		sb(stacks);
	}
	else if (pos_3 == MAX_MIDDLE + MIN_TOP)
	{
		sb(stacks);
		rb(stacks);
		sb(stacks);
		rrb(stacks);
	}
	else if (pos_3 == MAX_BOTTOM + MIN_TOP)
	{
		sb(stacks);
		rb(stacks);
		sb(stacks);
		rrb(stacks);
		sb(stacks);
	}
}

int is_sorted(t_node **stacks, int n, t_stack s_idx)
{
	int i;
	t_node *pos;

	if (n <= 1)
		return (1);
	pos = stacks[s_idx];
	i = 0;
	if (pos == NULL || pos->next==NULL)
		return (1);
	while (pos && i < n)
	{
		if (pos->next)
		{
			if (((s_idx == STACK_A) && (pos->next->n < pos->n))
				|| ((s_idx == STACK_B) && (pos->next->n > pos->n)))
				return (0);
		}
		pos = pos->next;
		i ++;
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
		if (size == 1)
			push_opposite(stacks,s_idx);
		else if (size == 2)
		{
			if (s_idx == STACK_A)
			{
				if (peek(stacks[s_idx]) > (peek(stacks[s_idx]->next)))
					sa(stacks);
			}
			else
			{
				if (peek(stacks[s_idx]) < (peek(stacks[s_idx]->next)))
					sb(stacks);
			}
			push_opposite(stacks,s_idx);
			push_opposite(stacks,s_idx);
		}
		else if (size == 3)
		{
			if (s_idx == STACK_A)
				sort_3(stacks,s_idx);
			else
				sort_3_reversed(stacks,s_idx);
			push_opposite(stacks,s_idx);
			push_opposite(stacks,s_idx);
			push_opposite(stacks,s_idx);
		}
		else
		{
			i = 0;
			if (is_sorted(stacks,size,s_idx))
			{
				while (i++ < size)
					push_opposite(stacks,s_idx);
				continue ;
			}
			else
			{
				ch_size = 0;
				median = find_median(stacks[s_idx],size);
				while (i < size)
				{
					if (s_idx == STACK_A)
					{
						if (peek(stacks[s_idx]) < median)
						{
							ch_size++;
							pb(stacks);
						}
						else
							ra(stacks);// add rra if last on stacks is < median
						i++;
					}
					else
					{
						if (peek(stacks[s_idx]) > median)
						{
							ch_size++;
							pa(stacks);
						}
						else
							rb(stacks);
						i++;
					}
				}
			}
			if (ch_size == 2) {
				if (s_idx == STACK_A)
				{
					if (peek(stacks[STACK_B]) < peek(stacks[STACK_B]->next))
						sb(stacks);
				} else {
					if (peek(stacks[STACK_A]) > peek(stacks[STACK_A]->next))
						sa(stacks);
				}
			}
			else if (ch_size == 3)
			{
				if (s_idx == STACK_A)
					sort_3_reversed(stacks,!s_idx);
				else
					sort_3(stacks,!s_idx);
			}
			else if (ch_size > 3)
			{
				new_chunk = NULL;
				new_chunk = push(new_chunk, ch_size);
				push_back(stacks, !s_idx, new_chunk);
				i = 0;
				while (i++ < ch_size)
				{
					if (s_idx == STACK_A)
						pb(stacks);
					else
						pa(stacks);
				}
			}
			if (count_stack(stacks[s_idx])!= size-ch_size)
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
				chunk = push(chunk, size - ch_size);
		}
	}
}

int sort(t_node **stacks){
	int size;
	t_node *chunk;

	chunk = NULL;
	size = count_stack(stacks[STACK_A]);
	chunk = first_split(stacks, size, chunk);
	if (count_stack(stacks[STACK_A]) == 2)
	{
		if (peek(stacks[STACK_A]) > peek(stacks[STACK_A]->next))
			sa(stacks);
	}
	else if (count_stack(stacks[STACK_A]) == 3)
	{
		sort_3_A(stacks,STACK_A);
	}
	push_back(stacks,STACK_B,chunk);
	return (0);
}

t_node *first_split(t_node **stacks, int size, t_node *chunk)
{
	int i;
	int median;
	int ch_size;

	while (size > 3)
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
				ra(stacks);
			i ++;
		}
		chunk = push(chunk,ch_size);
		size = count_stack(stacks[STACK_A]);
	}
	return chunk;
}