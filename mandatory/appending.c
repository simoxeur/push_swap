/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appending.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 05:01:24 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/19 15:14:38 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_target(t_stack **lst_a, t_stack **lst_b, t_count count)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *lst_b;
	while (i++ < count.count_b)
	{
		current->target = smallest_above(lst_a, count.count_a, current->data);
		current = current->next;
	}
}

void	append_cost(t_stack **lst_a, t_stack **lst_b, t_count c)
{
	int		i;
	t_stack	*n;

	n = *lst_b;
	i = 0;
	append_position_stack(lst_a, c.count_a);
	append_position_stack(lst_b, c.count_b);
	while (i++ < c.count_b)
	{
		if (n->position_up == 1 && n->target->position_up == 1)
			n->cost = n->index + n->target->index;
		else if (n->position_up == 1 && n->target->position_up == 0)
			n->cost = n->index + (c.count_a - n->target->index);
		else if (n->position_up == 0 && n->target->position_up == 1)
			n->cost = (c.count_b - n->index) + n->target->index;
		else if (n->position_up == 0 && n->target->position_up == 0)
			n->cost = (c.count_b - n->index) + (c.count_a - n->target->index);
		n = n->next;
	}
}

void	append_position_stack(t_stack **lst, int count)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *lst;
	while (i++ < count)
	{
		if (current->index < count / 2)
			current->position_up = 1;
		else
			current->position_up = 0;
		current = current->next;
	}
}

void	append_pos_median(t_stack **lst, int count, int median)
{
	int		i;
	t_stack	*current;

	current = *lst;
	i = 0;
	while (i++ < count)
	{
		if (current->data <= median)
			current->above_median = 0;
		else
			current->above_median = 1;
		current = current->next;
	}
}
