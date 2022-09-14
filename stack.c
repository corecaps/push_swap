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

	// TODO check for double entry
	if (top != NULL)
		bottom = get_bottom(top);
	else
		bottom = NULL;
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