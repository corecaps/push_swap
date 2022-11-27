//
// Created by corecaps on 23/09/22.
//

#include "push_swap.h"



int *stack_to_array(t_node *stack, int n)
{
	int 	*array;
	int 	size;
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
	fill_array(n, array, current_node);
	return (array);
}

void fill_array(int n, int *array, t_node *current_node)
{
	int i;

	i = 0;
	while (i < n && current_node)
	{
		array[i] = current_node->n;
		i ++;
		current_node = current_node->next;
	}
}

static void swap(int *a, int *b)
{
	int buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

static int	partition(int *array,int start,int end)
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

 void quick_sort(int *array, int start, int end)
{
	int split_index;
	if (start < end)
	{
		split_index = partition(array,start,end);
		quick_sort(array, start, split_index - 1);
		quick_sort(array, split_index + 1, end);
	}
}

int		get_median(int *array, int start, int end)
{
	quick_sort(array, start, end);
	return (array[((end - start) / 2) + start]);
}