/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 04:09:11 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/18 21:36:10 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_if_sorted(t_stack **lst_a, t_stack **lst_b, t_count count)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *lst_a;
	if (!lst_a)
		return ;
	while (i++ < count.count_a - 1)
	{
		if (current->data > current->next->data)
		{
			write(1, "KO\n", 3);
			free_stack(lst_a, count.count_a);
			free_stack(lst_b, count.count_b);
			exit(0);
		}
		current = current->next;
	}
	if (count.count_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
