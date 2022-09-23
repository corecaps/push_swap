//
// Created by corecaps on 23/09/22.
//

#include "push_swap.h"



int *stack_to_array(t_node *stack)
{
	int 	*array;
	int 	size;
	int 	i;
	t_node	*current_node;

	if (stack == NULL)
		return NULL;
	current_node = stack;
	size = count_stack(current_node);
	if (size == 0)
		return (NULL);
	array = malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);
	current_node = stack;
	i = 0;
	while (current_node)
	{
		array[i] = current_node->n;
		i ++;
		current_node = current_node->next;
	}
	return (array);
}
void swap(int *a, int *b)
{
	int buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

int	partition(int *array,int start,int end)
{
	int	pivot;
	int l_pos;
	int h_pos;

	pivot = array[end];
	l_pos = start - 1;
	h_pos = start;
	while (h_pos < end)
	{
		if (array[h_pos] < pivot)
		{
			l_pos ++;
			swap(&array[h_pos],&array[l_pos]);
		}
		h_pos ++;
	}
	swap(&array[l_pos + 1],&array[end]);
	return (l_pos + 1);
}

void sort_array(int *array,int start,int end)
{
	int split_index;
	if (start < end)
	{
		split_index = partition(array,start,end);
		sort_array(array,start, split_index - 1);
		sort_array(array,split_index + 1,end);
	}
}

int		get_pivot(int *array,int start,int end)
{
	sort_array(array,start,end);
	return (array[(end - start)/2]);
}