/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:36:18 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/19 14:37:02 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

static int	*extract_nbr(t_stack *lst, int count)
{
	t_stack	*current;
	int		i;
	int		*numbers;

	current = lst;
	i = 0;
	numbers = malloc(count * sizeof(int));
	if (!numbers)
		return (0);
	while (i < count)
	{
		numbers[i] = current->data;
		current = current->next;
		i++;
	}
	return (numbers);
}

int	get_median(t_stack *lst, int count)
{
	int		i;
	int		j;
	long	tmp;
	int		*sorted_nbr;

	i = -1;
	j = 0;
	tmp = 0;
	sorted_nbr = extract_nbr(lst, count);
	while (++i < count)
	{
		j = 0;
		while (j < count)
		{
			if (sorted_nbr[i] < sorted_nbr[j])
			{
				tmp = sorted_nbr[i];
				sorted_nbr[i] = sorted_nbr[j];
				sorted_nbr[j] = tmp;
			}
			j++;
		}
	}
	i = sorted_nbr[count / 2];
	return (free(sorted_nbr), i);
}
