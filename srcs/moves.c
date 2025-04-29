/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:27:34 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/04 04:48:04 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

void	swap(t_stack **lst, int count)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tird;
	t_stack	*last;

	if (!lst || !*lst || count == 0)
		return ;
	first = *lst;
	second = first->next;
	tird = second->next;
	if (tird == first)
		tird = second;
	last = last_node(lst, count);
	if (last == second)
		last = first;
	second->next = first;
	second->back = last;
	first->back = second;
	last->next = second;
	first->next = tird;
	tird->back = first;
	*lst = second;
	second->index--;
	first->index++;
}

void	rotate(t_stack **lst, int count)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*current;
	int		i;

	if (!lst || !*lst || count == 0)
		return ;
	i = 0;
	first = *lst;
	second = first->next;
	*lst = second;
	current = *lst;
	first->index += count - 1;
	while (i < count - 1)
	{
		current->index -= 1;
		current = current->next;
		i++;
	}
}

void	reverse_rotate(t_stack **lst, int count)
{
	t_stack	*last;
	t_stack	*current;
	int		i;

	if (!lst || !*lst || count == 0)
		return ;
	i = 1;
	last = last_node(lst, count);
	*lst = last;
	current = last->next;
	last->index -= count - 1;
	while (i < count)
	{
		current->index += 1;
		current = current->next;
		i++;
	}
}

void	push(t_stack **lst_from, t_stack **lst_to, int *c_from, int *c_to)
{
	t_stack	*first;

	if (!*lst_from || *c_from == 0)
		return ;
	first = *lst_from;
	if (*c_to > 0)
		add_front(lst_to, addnode(first->data, 0), c_to);
	if (*c_to == 0)
	{
		*lst_to = addnode(first->data, 0);
		++*c_to;
	}
	del_node(lst_from, first, c_from);
}
