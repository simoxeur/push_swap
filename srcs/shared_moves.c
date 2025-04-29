/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:19:06 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/03 06:23:43 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

void	ss(t_stack **lst_a, t_stack **lst_b, t_count count, int wr)
{
	swap(lst_a, count.count_a);
	swap(lst_b, count.count_b);
	if (wr == 1)
		write(1, "ss\n", 3);
}

void	rr(t_stack **lst_a, t_stack **lst_b, t_count count, int wr)
{
	rotate(lst_a, count.count_a);
	rotate(lst_b, count.count_b);
	if (wr == 1)
		write(1, "rr\n", 3);
}

void	rrr(t_stack **lst_a, t_stack **lst_b, t_count count, int wr)
{
	reverse_rotate(lst_a, count.count_a);
	reverse_rotate(lst_b, count.count_b);
	if (wr == 1)
		write(1, "rrr\n", 4);
}
