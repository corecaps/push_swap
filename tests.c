//
// Created by jgarcia on 9/14/22.
//
#include "push_swap.h"
void print_stack(t_node *top_a,t_node *top_b)
{
	int	a;
	int	b;

	ft_printf("A\t\t\t\t\t\t\t\tB\n");
	ft_printf("--------------------------------------\n");
	while (top_a || top_b)
	{
		if (top_a)
		{
			a = top_a->n;
			top_a = top_a->next;
		}
		else
		{
			a = 0;
		}
		if (top_b)
		{
			b = top_b->n;
			top_b = top_b->next;
		}
		else
		{
			b = 0;
		}
		ft_printf("%d\t\t\t\t\t%d\n",a,b);
	}
	ft_printf("--------------------------------------\n");
}