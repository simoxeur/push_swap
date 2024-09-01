/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 02:46:23 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/18 21:38:54 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "../utils/utils.h"
# include "../srcs/srcs.h"
# include "gnl/get_next_line.h"

void	read_instractions(t_stack **lst_a, t_stack **lst_b, t_count *count);
void	apply_move(t_stack **lst_a, t_stack **lst_b, t_count *count, char *mv);
void	check_if_sorted(t_stack **lst_a, t_count count);
long	*get_nbrs(char *str, int *count);

#endif