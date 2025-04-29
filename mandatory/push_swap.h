/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:23:19 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/18 21:38:56 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "../utils/utils.h"
# include "../srcs/srcs.h"

long	*get_nembers(char *str, int *count);
void	sort_nbrs(t_stack **lst_a, t_stack **lst_b, t_count *count);
void	append_target(t_stack **lst_a, t_stack **lst_b, t_count count);
void	append_cost(t_stack **lst_a, t_stack **lst_b, t_count count);
void	append_position_stack(t_stack **lst, int count);
void	append_pos_median(t_stack **lst, int count, int median);
void	botom_push(t_stack **lst_a, t_stack **lst_b, t_count *count);
void	sort_tree(t_stack **lst, int *count);
void	find_min(t_stack **lst, int count, int *min_id);
t_stack	*smallest_above(t_stack **lst, int count, int nbr);
void	r_up_a(t_stack **lst, int count, int id);
void	r_up_b(t_stack **lst, int count, int id);
void	b_to_a(t_stack **lst_a, t_stack **lst_b, t_count *count);

#endif