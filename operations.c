//
// Created by corecaps on 15/09/22.
//

#include "push_swap.h"

int sa(t_node **top_a)
{
	int a;
	int b;

	if (count_stack(*top_a) < 2)
		return (0);
	if (*top_a == NULL)
		return (-1);
	a = pop(top_a);
	b = pop(top_a);
	*top_a = push(*top_a,a);
	if (*top_a == NULL)
		return (-1);
	*top_a = push(*top_a,b);
	if (*top_a == NULL)
		return (-1);
	ft_printf("sa\n");
	return (0);
}

int sb(t_node **top_b)
{
	int a;
	int b;

	if (top_b == NULL)
		return (-1);
	if (count_stack(*top_b) < 2)
		return (0);
	a = pop(top_b);
	b = pop(top_b);
	*top_b = push(*top_b,a);
	if (*top_b == NULL)
		return (-1);
	*top_b = push(*top_b,b);
	if (*top_b == NULL)
		return (-1);
	ft_printf("sb\n");
	return (0);
}

int ss(t_node **top_a,t_node **top_b)
{
	if (sa(top_a) != 0)
		return (-1);
	if (sb(top_b) != 0)
		return (-1);
	ft_printf("ss\n");
	return (0);
}

int pa(t_node **top_a,t_node **top_b)
{
	int a;

	if (*top_b == NULL)
		return (-1);
	a = pop(top_b);
	*top_a = push(*top_a,a);
	if (*top_a == NULL)
		return (-1);
	ft_printf("pa\n");
	return (0);
}

int pb(t_node **top_a,t_node **top_b)
{
	int a;

	if (*top_a == NULL)
		return (-1);
	a = pop(top_a);
	*top_b = push(*top_b,a);
	if (*top_b == NULL)
		return (-1);
	ft_printf("pb\n");
	return (0);
}

int ra(t_node **top_a)
{
	int a;

	if (top_a == NULL)
		return (-1);
	a = pop(top_a);
	*top_a = push_bottom(*top_a, a);
	if (*top_a == NULL)
		return (-1);
	ft_printf("ra\n");
	return (0);
}

int rb(t_node **top_b)
{
	int a;

	if (top_b == NULL)
		return (-1);
	a = pop(top_b);
	*top_b = push_bottom(*top_b, a);
	if (*top_b == NULL)
		return (-1);
	ft_printf("rb\n");
	return (0);
}

int rr(t_node **top_a,t_node **top_b)
{
	ra(top_a);
	if (*top_a == NULL)
		return (-1);
	rb(top_b);
	if (*top_b == NULL)
		return (-1);
	ft_printf("rr\n");
	return (0);
}
/*
int rra(t_node **top_a)
{
	t_node *bottom;

}

int rrb(t_node *top_a,t_node *top_b)
{

}

int rrr(t_node *top_a,t_node *top_b)
{

}*/