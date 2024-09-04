/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 05:10:13 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/19 15:17:42 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handl_five(t_stack **lst_a, t_stack **lst_b, t_count *count)
{
	int	min_id;

	min_id = 0;
	while (count->count_a > 3)
	{
		find_min(lst_a, count->count_a, &min_id);
		r_up_a(lst_a, count->count_a, min_id);
		pb(lst_a, lst_b, &count->count_a, &count->count_b);
	}
}

static void	find_lower(t_stack **lst, int count, int *id)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *lst;
	while (i++ < count)
	{
		if (current->above_median == 0)
		{
			*id = current->index;
			return ;
		}
		current = current->next;
	}
	*id = -1;
}

void	botom_push(t_stack **lst_a, t_stack **lst_b, t_count *count)
{
	int		id;

	id = 0;
	if (count->count_a == 5 || count->count_a == 4)
		handl_five(lst_a, lst_b, count);
	while (count->count_a > 3)
	{
		find_lower(lst_a, count->count_a, &id);
		if (id == -1)
			return ;
		r_up_a(lst_a, count->count_a, id);
		pb(lst_a, lst_b, &count->count_a, &count->count_b);
	}
}
