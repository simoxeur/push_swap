/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbr2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 05:23:21 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/19 15:06:58 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tree(t_stack **lst, int *count)
{
	if ((*lst)->data < (*lst)->next->data)
	{
		if ((*lst)->data < (*lst)->next->next->data
			&& (*lst)->next->data > (*lst)->next->next->data)
		{
			sa(lst, *count);
			ra(lst, *count);
		}
		else if ((*lst)->data > (*lst)->next->next->data)
			rra(lst, *count);
	}
	else
	{
		if ((*lst)->data < (*lst)->next->next->data)
			sa(lst, *count);
		else
		{
			ra(lst, *count);
			if ((*lst)->data > (*lst)->next->data)
				sa(lst, *count);
		}
	}
}

void	find_min(t_stack **lst, int count, int *min_id)
{
	int		i;
	t_stack	*current;
	t_stack	*min;

	current = *lst;
	min = *lst;
	i = 0;
	while (i++ < count)
	{
		if (current->data < min->data)
			min = current;
		current = current->next;
	}
	*min_id = min->index;
}

t_stack	*smallest_above(t_stack **lst, int count, int nbr)
{
	int		i;
	t_stack	*current;
	t_stack	*smallest_max;

	i = 0;
	current = *lst;
	while (i++ < count)
	{
		if (current->data > nbr)
			break ;
		current = current->next;
	}
	smallest_max = current;
	while (i++ < count + 1)
	{
		if (current->data > nbr && current->data < smallest_max->data)
			smallest_max = current;
		current = current->next;
	}
	return (smallest_max);
}

void	r_up_a(t_stack **lst, int count, int id)
{
	int	i;

	i = 0;
	if (id == 0)
		return ;
	if (id <= count / 2)
		while (i++ < id)
			ra(lst, count);
	else
		while (i++ < count - id)
			rra(lst, count);
}

void	r_up_b(t_stack **lst, int count, int id)
{
	int	i;

	i = 0;
	if (id == 0)
		return ;
	if (id <= count / 2)
		while (i++ < id)
			rb(lst, count);
	else
		while (i++ < count - id)
			rrb(lst, count);
}
