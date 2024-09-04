/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:49:59 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/04 04:43:17 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	moving(t_stack **lst_a, t_stack **lst_b, t_count *count, char *mv)
{
	if (ft_strcmp_4moves(mv, "sa") == 0)
		swap(lst_a, count->count_a);
	else if (ft_strcmp_4moves(mv, "sb") == 0)
		swap(lst_b, count->count_b);
	else if (ft_strcmp_4moves(mv, "ra") == 0)
		rotate(lst_a, count->count_a);
	else if (ft_strcmp_4moves(mv, "rb") == 0)
		rotate(lst_b, count->count_b);
	else if (ft_strcmp_4moves(mv, "rra") == 0)
		reverse_rotate(lst_a, count->count_a);
	else if (ft_strcmp_4moves(mv, "rrb") == 0)
		reverse_rotate(lst_b, count->count_b);
	else if (ft_strcmp_4moves(mv, "pb") == 0)
		push(lst_a, lst_b, &count->count_a, &count->count_b);
	else if (ft_strcmp_4moves(mv, "pa") == 0)
		push(lst_b, lst_a, &count->count_b, &count->count_a);
	else if (ft_strcmp_4moves(mv, "ss") == 0)
		ss(lst_a, lst_b, *count, 0);
	else if (ft_strcmp_4moves(mv, "rr") == 0)
		rr(lst_a, lst_b, *count, 0);
	else if (ft_strcmp_4moves(mv, "rrr") == 0)
		rrr(lst_a, lst_b, *count, 0);
	free(mv);
}

void	app_move(t_stack **lst_a, t_stack **lst_b, t_count *count, t_move *mv)
{
	t_move	*tmp;

	tmp = NULL;
	while (mv)
	{
		moving(lst_a, lst_b, count, mv->move);
		tmp = mv;
		mv = mv->next;
		free(tmp);
	}
}
