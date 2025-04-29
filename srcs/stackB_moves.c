/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackB_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:16:41 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/03 06:28:23 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

void	sb(t_stack **lst_b, int count_b)
{
	swap(lst_b, count_b);
	write(1, "sb\n", 3);
}

void	rb(t_stack **lst_b, int count_b)
{
	rotate(lst_b, count_b);
	write(1, "rb\n", 3);
}

void	rrb(t_stack **lst_b, int count_b)
{
	reverse_rotate(lst_b, count_b);
	write(1, "rrb\n", 4);
}

void	pa(t_stack **lst_b, t_stack **lst_a, int *count_b, int *count_a)
{
	push(lst_b, lst_a, count_b, count_a);
	write(1, "pa\n", 3);
}
