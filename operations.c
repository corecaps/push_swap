//
// Created by corecaps on 15/09/22.
//

#include "push_swap.h"

int sa(t_node **stacks)
{
	int a;
	int b;

	if (count_stack(stacks[STACK_A]) < 2)
		return (0);
	if (stacks[STACK_A] == NULL)
		return (-1);
	a = pop(&stacks[STACK_A]);
	b = pop(&stacks[STACK_A]);
	stacks[STACK_A] = push(stacks[STACK_A], a);
	if (stacks[STACK_A] == NULL)
		return (-1);
	stacks[STACK_A] = push(stacks[STACK_A], b);
	if (stacks[STACK_A] == NULL)
		return (-1);
	ft_printf("sa\n");
	return (0);
}

int sb(t_node **stacks)
{
	int a;
	int b;

	if (stacks[STACK_B] == NULL)
		return (-1);
	if (count_stack(stacks[STACK_B]) < 2)
		return (0);
	a = pop(&stacks[STACK_B]);
	b = pop(&stacks[STACK_B]);
	stacks[STACK_B] = push(stacks[STACK_B], a);
	if (stacks[STACK_B] == NULL)
		return (-1);
	stacks[STACK_B] = push(stacks[STACK_B], b);
	if (stacks[STACK_B] == NULL)
		return (-1);
	ft_printf("sb\n");
	return (0);
}

int ss(t_node **stacks)
{
	if (sa(stacks) != 0)
		return (-1);
	if (sb(stacks) != 0)
		return (-1);
	ft_printf("ss\n");
	return (0);
}

int pa(t_node **stacks)
{
	int a;

	if (stacks[STACK_B] == NULL)
		return (-1);
	a = pop(&stacks[STACK_B]);
	stacks[STACK_A] = push(stacks[STACK_A],a);
	if (stacks[STACK_A] == NULL)
		return (-1);
	ft_printf("pa\n");
	return (0);
}

int pb(t_node **stacks)
{
	int a;

	if (stacks[STACK_A] == NULL)
		return (-1);
	a = pop(&stacks[STACK_A]);
	stacks[STACK_B] = push(stacks[STACK_B],a);
	if (stacks[STACK_B] == NULL)
		return (-1);
	ft_printf("pb\n");
	return (0);
}

int ra(t_node **stacks)
{
	int a;

	if (stacks[STACK_A] == NULL)
		return (-1);
	a = pop(&stacks[STACK_A]);
	stacks[STACK_A] = push_bottom(stacks[STACK_A], a);
	if (stacks[STACK_A] == NULL)
		return (-1);
	ft_printf("ra\n");
	return (0);
}

int rb(t_node **stacks)
{
	int a;

	if (stacks[STACK_B] == NULL)
		return (-1);
	a = pop(&stacks[STACK_B]);
	stacks[STACK_B] = push_bottom(stacks[STACK_B], a);
	if (stacks[STACK_B] == NULL)
		return (-1);
	ft_printf("rb\n");
	return (0);
}

int rr(t_node **stacks)
{
	ra(stacks);
	if (stacks[STACK_A] == NULL)
		return (-1);
	rb(stacks);
	if (stacks[STACK_B] == NULL)
		return (-1);
	ft_printf("rr\n");
	return (0);
}

int rra(t_node **stacks)
{
	int	n;

	n = pop_bottom(&stacks[STACK_A]);
	stacks[STACK_A] = push(stacks[STACK_A],n);
	if (stacks[STACK_A] == NULL)
		return (-1);
	ft_printf("rra\n");
	return (0);
}

int rrb(t_node **stacks)
{
	int n;

	n = pop_bottom(&stacks[STACK_B]);
	stacks[STACK_B] = push(stacks[STACK_B],n);
	if (stacks[STACK_B] == NULL)
		return (1);
	ft_printf("rrb\n");
	return (0);
}

int rrr(t_node **stacks)
{
	rra(stacks);
	rrb(stacks);
	ft_printf("rrr\n");
	return (0);
}