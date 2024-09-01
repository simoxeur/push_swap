/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:19:11 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/04 05:20:20 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

t_stack	*addnode(int data, int index)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = index;
	new->next = new;
	new->back = new;
	return (new);
}

void	add_back(t_stack **lst, t_stack *node, int count)
{
	t_stack	*first;
	t_stack	*last;

	if (!lst || !*lst)
		return ;
	first = *lst;
	last = *lst;
	last = last_node(lst, count);
	last->next = node;
	node->back = last;
	node->next = first;
	first->back = node;
}

t_stack	*last_node(t_stack **lst, int count)
{
	t_stack	*last;

	if (!lst || !*lst)
		return (NULL);
	last = *lst;
	while (last->index != count - 1)
		last = last->next;
	return (last);
}

void	add_front(t_stack **lst, t_stack *node, int *count)
{
	int		i;
	t_stack	*first;
	t_stack	*last;
	t_stack	*current;

	if (!lst || !*lst)
		return ;
	i = 0;
	first = *lst;
	last = last_node(lst, *count);
	node->next = first;
	node->back = last;
	first->back = node;
	last->next = node;
	if (last)
		last->next = node;
	*lst = node;
	current = node->next;
	while (i < *count)
	{
		current->index = i + 1;
		i++;
		current = current->next;
	}
	++*count;
}

void	del_node(t_stack **lst, t_stack *node, int *count)
{
	int		i;
	t_stack	*prev;
	t_stack	*sec;
	t_stack	*current;

	i = 0;
	if (!lst || !*lst || !node || *count == 0)
		return ;
	prev = node->back;
	sec = node->next;
	if (prev)
		prev->next = sec;
	if (sec)
		sec->back = prev;
	if (node == *lst)
		*lst = sec;
	--*count;
	current = sec;
	while (i++ < *count)
	{
		current->index--;
		current = current->next;
	}
	free(node);
	node = NULL;
}
