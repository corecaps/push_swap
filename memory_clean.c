//
// Created by corecaps on 23/09/22.
//
#include "push_swap.h"

void clean_memory(t_node *stack)
{
	t_node *prev;

	if (stack == NULL)
		return ;
	prev = NULL;
	while (stack->next)
	{
		prev = stack;
		stack = stack->next;
		free(prev);
	}
	free (stack);
}