/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:22:16 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/19 15:35:04 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

t_stack	*loading(long *numbers, int count)
{
	t_stack	*lst;
	int		i;

	lst = NULL;
	i = 0;
	if (!numbers)
		return (NULL);
	lst = addnode(numbers[i], i);
	if (!lst)
		return (free(numbers), NULL);
	i++;
	while (i < count)
	{
		add_back(&lst, addnode(numbers[i], i), i);
		i++;
	}
	free(numbers);
	return (lst);
}
