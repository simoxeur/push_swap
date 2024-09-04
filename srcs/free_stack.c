/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:17:03 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/04 05:19:02 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

void	free_stack(t_stack **lst, int count)
{
	if (!lst || !*lst || count == 0)
		return ;
	while (count > 1)
		del_node(lst, *lst, &count);
	free(*lst);
}
