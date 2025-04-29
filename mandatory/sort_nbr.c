/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:46:49 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/19 15:30:37 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_nbrs(t_stack **lst_a, t_stack **lst_b, t_count *count)
{
	int	med;

	med = 0;
	while (count->count_a > 3)
	{
		med = get_median(*lst_a, count->count_a);
		append_pos_median(lst_a, count->count_a, med);
		append_position_stack(lst_a, count->count_a);
		botom_push(lst_a, lst_b, count);
	}
	if (count->count_a == 0 || count->count_a == 1)
		return ;
	if (count->count_a == 2)
		sa(lst_a, count->count_a);
	if (count->count_a == 3)
		sort_tree(lst_a, &count->count_a);
	b_to_a(lst_a, lst_b, count);
}
