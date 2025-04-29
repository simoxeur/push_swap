/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:06:25 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/19 15:40:51 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "../utils/utils.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				position_up;
	int				cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*back;
}	t_stack;

typedef struct s_count
{
	int	count_a;
	int	count_b;
	int	cheap_id;
	int	cheap_target_id;
}	t_count;

t_stack		*addnode(int data, int index);
t_stack		*last_node(t_stack **lst, int count);
t_stack		*loading(long *numbers, int count);
void		add_back(t_stack **lst, t_stack *node, int count);
void		add_front(t_stack **lst, t_stack *node, int *count);
void		del_node(t_stack **lst, t_stack *node, int *count);
void		free_stack(t_stack **lst, int count);
char		*join_args(char *argv[]);
long		*get_nembers(char *str, int *count);
int			get_median(t_stack *lst, int count);
void		swap(t_stack **lst, int count);
void		rotate(t_stack **lst, int count);
void		reverse_rotate(t_stack **lst, int count);
void		push(t_stack **lst_from, t_stack **lst_to, int *c_from, int *c_to);
void		sa(t_stack **lst, int count);
void		ra(t_stack **lst, int count);
void		rra(t_stack **lst, int count);
void		pb(t_stack **lst_a, t_stack **lst_b, int *count_a, int *count_b);
void		sb(t_stack **lst, int count);
void		rb(t_stack **lst, int count);
void		rrb(t_stack **lst, int count);
void		pa(t_stack **lst_b, t_stack **lst_a, int *count_b, int *count_a);
void		ss(t_stack **lst_a, t_stack **lst_b, t_count count, int wr);
void		rr(t_stack **lst_a, t_stack **lst_b, t_count count, int wr);
void		rrr(t_stack **lst_a, t_stack **lst_b, t_count count, int wr);

#endif