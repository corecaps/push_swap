//
// Created by corecaps on 15/11/22.
//

#include <limits.h>
#include "push_swap.h"

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
//			ft_printf("%d ? %d\n", pos->n,pos->next->n);
			if (s_idx == STACK_A)
			{
				if (pos->next->n < pos->n)
				{
//					ft_printf("not sorted\n");
					return (0);
				}
			}
			else
			{
				if (pos->next->n > pos->n)
				{
//					ft_printf("not sorted\n");
					return (0);
				}
			}
		}
		pos = pos->next;
		i ++;
	}
//	ft_printf("SORTED");
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
//	int j;
	t_node *new_chunk;

	new_chunk = NULL;
//	ft_printf("======================================================\n");
//	ft_printf("New call to pushback:\t Stack:%c\n",s_idx ? 'b' : 'a');
//	t_node *pos;
//	pos = chunk;
//	i = 0;
//	while (pos){
//		ft_printf("%d : n : %d\n",i,pos->n);
//		pos = pos->next;
//		i ++;
//	}
//	ft_printf("\n");
	while (chunk)
	{
		size = pop(&chunk);
//		ft_printf("Pushing Back chunk of size :%d\nstate of chunk stack\n",size);
//		pos = chunk;
//		j = 0;
//		while (pos){
//			ft_printf("%d:\tn->%d\n",j,pos->n);
//			pos = pos->next;
//			j ++;
//		}
//		print_stack(stacks[STACK_A],stacks[STACK_B]);
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
			if (is_sorted(stacks,size,s_idx))
			{
				i = 0;
				while (i < size)
				{
					push_opposite(stacks,s_idx);
					i++;
				}
				continue ;
			}
			else
			{
				ch_size = 0;
				i = 0;
				// find median
				median = find_median(stacks[s_idx],size);
	//			ft_printf("\n median is :\t%d\n",median);
				while (i < size)
				{
					// push to opposite side everything above or greater
					// than median depending on stack
					if (s_idx == STACK_A)
					{
						//					ft_printf("origine stack A\n");
						if (peek(stacks[s_idx]) < median)
						{
							//						ft_printf("%d is less than %d pushing to B\n", peek(stacks[s_idx]),median);
							ch_size++;
							pb(stacks);
						}
						else
						{
							//						ft_printf("%d is higher than %d rotate stack A\n", peek(stacks[s_idx]), median);
							ra(stacks);// add rra if last on stacks is < median
						}
						i++;
					}
					else
					{
						//					ft_printf("origine stack B\n");
						if (peek(stacks[s_idx]) > median)
						{
							//						ft_printf("%d is higher than %d pushing to A\n", peek(stacks[s_idx]),median);
							ch_size++;
							pa(stacks);
						}
						else
						{
							//						ft_printf("%d is lesser than %d rotate stack B\n", peek(stacks[s_idx]), median);
							rb(stacks);
						}
						i++;
					}
				}
			}
			if (ch_size == 2) {
				if (s_idx == STACK_A)
				{
					if (peek(stacks[STACK_B]) < peek(stacks[STACK_B]->next))
					{
						sb(stacks);
					}
				} else {
					if (peek(stacks[STACK_A]) > peek(stacks[STACK_A]->next))
					{
						sa(stacks);
					}
				}
			}
			else if (ch_size > 2)
			{
				// create a new chunk stack to process the recursive call
				new_chunk = NULL;
				new_chunk = push(new_chunk, ch_size);
				// recursive call to push_back if more than 2 push
				push_back(stacks, !s_idx, new_chunk);
				i = 0;
				// ???? Not working
				while (i < ch_size)
				{
					if (s_idx == STACK_A)
						pb(stacks);
					else
						pa(stacks);
					i ++;
				}
			}
//			ft_printf("i have pushed %d elements to stack %c\n", ch_size, !s_idx ? 'b' : 'a');
//			print_stack(stacks[STACK_A],stacks[STACK_B]);
			// if == 2 push check order and swap if necessary
			// if not last chunk
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
			{
				chunk = push(chunk, size - ch_size);
//				ft_printf("Still %d elements in chunk\nchunk stack state\n",size-ch_size);
//				pos = chunk;
//				j = 0;
//				while (pos){
//					ft_printf("%d : n : %d\n",j,pos->n);
//					pos = pos->next;
//					j ++;
//				}
//				ft_printf("\n");

			}
		}
	}
//	ft_printf("============================================================\n");
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
			{
				ra(stacks); // add rra if last on stacks is < median
			}
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
//	i = is_sorted(stacks[STACK_A], count_stack(stacks[STACK_A]));
//	ft_printf("is sorted ? %c\n",i ? 'y' : 'n');
	return (0);
}