/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:10:16 by jgarcia           #+#    #+#             */
/*   Updated: 2022/09/01 12:24:01 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*push(t_node *top, int n)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->next = top;
	new->n = n;
	return (new);
}

t_node	*push_bottom(t_node *top, int n)
{
	t_node	*bottom;
	t_node	*new;

	if (top != NULL)
		bottom = get_bottom(top);
	else
		bottom = NULL;
	if (top != NULL)
	{
		if (is_in_stack(top,n))
			return(NULL);
	}
	new = malloc(sizeof (t_node));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->n = n;
	if (bottom == NULL)
		top = new;
	else
		bottom->next = new;
	return (top);
}

int	pop(t_node **top)
{
	int		n;
	t_node	*tmp;

	n = (*top)->n;
	tmp = *top;
	*top = (*top)->next;
	free (tmp);
	return (n);
}

int pop_bottom(t_node **top)
{
	int		n;
	t_node	*tmp;
	t_node	*prev;

	if ((*top) == NULL)
		return (0);
	tmp = *top;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	n =  tmp->n;
	prev->next = NULL;
	free(tmp);
	return (n);
}

t_node	*get_bottom(t_node *top)
{
	t_node	*bottom;

	bottom = top;
	while (bottom->next)
	{
		bottom = bottom->next;
	}
	return (bottom);
}

int is_in_stack(t_node *top_a,int n)
{
	while(top_a)
	{
		if (top_a->n == n)
			return (1);
		top_a = top_a->next;
	}
	return (0);
}

int count_stack(t_node *top)
{
	int	count;

	count = 0;
	if (top == NULL)
		return (count);
	while (top)
	{
		count ++;
		top = top->next;
	}
	return (count);
}

int peek(t_node *top)
{
	return (top->n);
}