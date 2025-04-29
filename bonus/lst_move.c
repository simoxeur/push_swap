/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 04:09:11 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/21 21:36:10 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_move	*new_move(char *move)
{
	t_move	*new;

	new = (t_move *)malloc(sizeof(t_move));
	if (!new)
		return (NULL);
	new->move = move;
	new->next = NULL;
	return (new);
}

void	add_move(t_move **lst, char *mv)
{
	t_move	*last;
	t_move	*move;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new_move(mv);
		return ;
	}
	last = *lst;
	move = new_move(mv);
	while (last->next)
		last = last->next;
	last->next = move;
	return ;
}

void	del_moves(t_move *lst)
{
	t_move	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->move);
		free(lst);
		lst = tmp;
	}
}
