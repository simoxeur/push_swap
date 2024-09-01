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

void	apply_move(t_stack **lst_a, t_stack **lst_b, t_count *count, char *move)
{
	if (ft_strcmp_4moves(move, "sa") == 0)
		swap(lst_a, count->count_a);
	else if (ft_strcmp_4moves(move, "sb") == 0)
		swap(lst_b, count->count_b);
	else if (ft_strcmp_4moves(move, "ra") == 0)
		rotate(lst_a, count->count_a);
	else if (ft_strcmp_4moves(move, "rb") == 0)
		rotate(lst_b, count->count_b);
	else if (ft_strcmp_4moves(move, "rra") == 0)
		reverse_rotate(lst_a, count->count_a);
	else if (ft_strcmp_4moves(move, "rrb") == 0)
		reverse_rotate(lst_b, count->count_b);
	else if (ft_strcmp_4moves(move, "pb") == 0)
		push(lst_a, lst_b, &count->count_a, &count->count_b);
	else if (ft_strcmp_4moves(move, "pa") == 0)
		push(lst_b, lst_a, &count->count_b, &count->count_a);
	else if (ft_strcmp_4moves(move, "ss") == 0)
		ss(lst_a, lst_b, *count, 0);
	else if (ft_strcmp_4moves(move, "rr") == 0)
		rr(lst_a, lst_b, *count, 0);
	else if (ft_strcmp_4moves(move, "rrr") == 0)
		rrr(lst_a, lst_b, *count, 0);
	else
		error_msg();
	free(move);
}
