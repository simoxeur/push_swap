/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:38:43 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/04 02:01:22 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	exist(char *move)
{
	if (ft_strcmp_4moves(move, "sa") == 0
		|| ft_strcmp_4moves(move, "sb") == 0
		|| ft_strcmp_4moves(move, "ra") == 0
		|| ft_strcmp_4moves(move, "rb") == 0
		|| ft_strcmp_4moves(move, "rra") == 0
		|| ft_strcmp_4moves(move, "rrb") == 0
		|| ft_strcmp_4moves(move, "pb") == 0
		|| ft_strcmp_4moves(move, "pa") == 0
		|| ft_strcmp_4moves(move, "ss") == 0
		|| ft_strcmp_4moves(move, "rr") == 0
		|| ft_strcmp_4moves(move, "rrr") == 0)
		return (1);
	else
		return (0);
}

void	read_instractions(t_stack **lst_a, t_stack **lst_b, t_count *count)
{
	char	*move;
	t_move	*lst_moves;

	move = NULL;
	lst_moves = NULL;
	while (1)
	{
		move = get_next_line(0);
		if (!move || !*move)
			break ;
		if (exist(move))
			add_move(&lst_moves, move);
		else
			return (free_stack(lst_a, count->count_a), del_moves(lst_moves),
				free(move), error_msg());
		move = NULL;
	}
	app_move(lst_a, lst_b, count, lst_moves);
}
