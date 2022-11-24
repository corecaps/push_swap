//
// Created by jgarcia on 9/14/22.
//
#include "push_swap.h"
#include <stdio.h>
//void test_3_sort()
//{
//	t_node **stacks;
//
//	stacks = malloc(sizeof (t_node *) * 2);
//	stacks[STACK_A] = NULL;
//	stacks[STACK_B] = NULL;
//
//	stacks[STACK_A] = push(stacks[STACK_A],3);
//	stacks[STACK_A] = push(stacks[STACK_A], 2);
//	stacks[STACK_A] = push(stacks[STACK_A],1);
//	print_stack(stacks[STACK_A],stacks[STACK_B]);
//	sort_3(stacks,STACK_A);
//	print_stack(stacks[STACK_A],stacks[STACK_B]);
//
//	stacks[STACK_A] = push(stacks[STACK_A],2);
//	stacks[STACK_A] = push(stacks[STACK_A], 3);
//	stacks[STACK_A] = push(stacks[STACK_A],1);
//	print_stack(stacks[STACK_A],stacks[STACK_B]);
//	sort_3(stacks,STACK_A);
//	print_stack(stacks[STACK_A],stacks[STACK_B]);
//}
void print_chunk(t_chunk chunk,t_node *top_a,t_node *top_b)
{
	t_node *pos;
	if (chunk.stack < STACK_A || chunk.stack > STACK_B)
		return ;
	if (chunk.stack == STACK_A)
		pos = top_a;
	else
		pos = top_b;
	int n = chunk.n;
	int i = 0;
	ft_printf("\n================\n");
	ft_printf("A:\t %p\tB:\t %p\tCurrent chunk :\t stack: %p\t n:%d\n",top_a,top_b,pos,n);
	while (i < n) {
		ft_printf("%d\t",pos->n);
		pos = pos->next;
		i ++;
	}
	ft_printf("\n================\n");
}

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
			printf("%d\t\t\t\t\t",a);
		}
		else
		{
			printf("(empty)\t\t\t\t\t");
		}
		if (top_b)
		{
			b = top_b->n;
			top_b = top_b->next;
			printf("%d\n",b);
		}
		else
		{
			printf("(empty)\n");
		}
	}
	ft_printf("--------------------------------------\n");
}


//void operations_test(t_node **top_a, t_node **top_b)
//{
//	int *array;
//	int size;
//	print_stack(*top_a,*top_b);
//	ft_printf("numbers in stack a: %d\n", count_stack(*top_a));
//	ft_printf("numbers in stack b: %d\n", count_stack(*top_b));
//	sa(top_a);
//	print_stack((*top_a), (*top_b));
//	pb(top_a, top_b);
//	pb(top_a, top_b);
//	pb(top_a, top_b);
//	print_stack((*top_a), (*top_b));
//	sb(top_b);
//	print_stack((*top_a), (*top_b));
//	ss(top_a, top_b);
//	print_stack((*top_a), (*top_b));
//	ra(top_a);
//	rb(top_b);
//	print_stack((*top_a), (*top_b));
//	rr(top_a,top_b);
//	print_stack((*top_a), (*top_b));
//	rrr(top_a,top_b);
//	print_stack((*top_a), (*top_b));
//	pa(top_a, top_b);
//	pa(top_a, top_b);
//	pa(top_a,top_b);
//	print_stack((*top_a), (*top_b));
//	size = count_stack(*top_a);
//	array = stack_to_array(*top_a,size);
//	sort_array(array,0, size - 1);
//	ft_printf("=========================================================\nsorted array\n");
//	for (int i=0;i < size - 1;i ++)
//		ft_printf("%d\n",array[i]);
//	ft_printf("pivot : %d\n", get_pivot(array,0,size-1));
//	free(array);
//}