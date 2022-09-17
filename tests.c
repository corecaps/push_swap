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
			ft_printf("%d\t\t\t\t\t",a);
		}
		else
		{
			ft_printf("(empty)\t\t\t\t\t");
		}
		if (top_b)
		{
			b = top_b->n;
			top_b = top_b->next;
			ft_printf("%d\n",b);
		}
		else
		{
			ft_printf("(empty)\n");
		}
	}
	ft_printf("--------------------------------------\n");
}


void operations_test(t_node **top_a, t_node **top_b)
{
	sa(top_a);
	print_stack((*top_a), (*top_b));
	pb(top_a, top_b);
	pb(top_a, top_b);
	pb(top_a, top_b);
	print_stack((*top_a), (*top_b));
	sb(top_b);
	print_stack((*top_a), (*top_b));
	ss(top_a, top_b);
	print_stack((*top_a), (*top_b));
	ra(top_a);
	rb(top_b);
	print_stack((*top_a), (*top_b));
	rr(top_a,top_b);
	print_stack((*top_a), (*top_b));
	rrr(top_a,top_b);
	print_stack((*top_a), (*top_b));
	pa(top_a, top_b);
	pa(top_a, top_b);
	print_stack((*top_a), (*top_b));
}