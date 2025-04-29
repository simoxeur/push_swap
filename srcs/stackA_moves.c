/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackA_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:12:22 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/04 08:53:59 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

void	sa(t_stack **lst_a, int count_a)
{
	swap(lst_a, count_a);
	write(1, "sa\n", 3);
}

void	ra(t_stack **lst_a, int count_a)
{
	rotate(lst_a, count_a);
	write(1, "ra\n", 3);
}

void	rra(t_stack **lst_a, int count_a)
{
	reverse_rotate(lst_a, count_a);
	write(1, "rra\n", 4);
}

void	pb(t_stack **lst_a, t_stack **lst_b, int *count_a, int *count_b)
{
	push(lst_a, lst_b, count_a, count_b);
	write(1, "pb\n", 3);
}
