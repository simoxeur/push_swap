/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 02:45:24 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/19 15:29:48 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	long	*nbr;
	char	*joined_args;
	t_stack	*lst_a;
	t_stack	*lst_b;
	t_count	count;

	nbr = NULL;
	lst_a = NULL;
	lst_b = NULL;
	count.count_a = 0;
	count.count_b = 0;
	if (argc == 2 && argv[1][0] == '\0')
		error_msg();
	if (argc >= 2)
	{
		joined_args = join_args(argv);
		nbr = get_nbrs(joined_args, &count.count_a);
		lst_a = loading(nbr, count.count_a);
		read_instractions(&lst_a, &lst_b, &count);
		check_if_sorted(&lst_a, &lst_b, count);
		free_stack(&lst_a, count.count_a);
		free_stack(&lst_b, count.count_b);
		lst_a = NULL;
		lst_b = NULL;
	}
}
