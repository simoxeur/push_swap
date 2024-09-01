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

void	read_instractions(t_stack **lst_a, t_stack **lst_b, t_count *count)
{
	char	*move;

	move = NULL;
	while (1)
	{
		move = get_next_line(0);
		if (!move || !*move)
			break ;
		apply_move(lst_a, lst_b, count, move);
		move = NULL;
	}
}
