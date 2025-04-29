/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 05:14:36 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/18 18:37:30 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_cheapest(t_stack **lst, t_count *count)
{
	int		i;
	t_stack	*current;
	t_stack	*cheapest_node;

	i = 0;
	current = *lst;
	cheapest_node = current;
	while (i++ < count->count_b)
	{
		if (current->cost < cheapest_node->cost)
			cheapest_node = current;
		current = current->next;
	}
	count->cheap_id = cheapest_node->index;
	count->cheap_target_id = cheapest_node->target->index;
}

static void	ids_update(t_count *c)
{
	if (c->cheap_id < c->count_b / 2 && c->cheap_target_id < c->count_a / 2)
	{
		c->cheap_id--;
		c->cheap_target_id--;
	}
	if (c->cheap_id >= c->count_b / 2 && c->cheap_target_id >= c->count_a / 2)
	{
		c->cheap_id++;
		c->cheap_target_id++;
	}
}

static void	rotate_to(t_stack **lst_a, t_stack **lst_b, t_count *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c->cheap_id < c->count_b / 2 && c->cheap_target_id < c->count_a / 2)
	{
		while (i++ < c->cheap_id && j++ < c->cheap_target_id)
		{
			rr(lst_a, lst_b, *c, 1);
			ids_update(c);
		}
	}
	if (c->cheap_id >= c->count_b / 2 && c->cheap_target_id >= c->count_a / 2)
	{
		while (i++ < c->count_b - c->cheap_id
			&& j++ < c->count_a - c->cheap_target_id)
		{
			rrr(lst_a, lst_b, *c, 1);
			ids_update(c);
		}
	}
	r_up_a(lst_a, c->count_a, c->cheap_target_id);
	r_up_b(lst_b, c->count_b, c->cheap_id);
}

void	b_to_a(t_stack **lst_a, t_stack **lst_b, t_count *count)
{
	int		min_id;

	min_id = 0;
	while (count->count_b)
	{
		append_target(lst_a, lst_b, *count);
		append_cost(lst_a, lst_b, *count);
		find_cheapest(lst_b, count);
		rotate_to(lst_a, lst_b, count);
		pa(lst_b, lst_a, &count->count_b, &count->count_a);
	}
	find_min(lst_a, count->count_a, &min_id);
	r_up_a(lst_a, count->count_a, min_id);
}
