/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:41:53 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/04 05:41:54 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	*msg_error(int valide)
{
	if (valide == -1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (valide == -2)
		exit (EXIT_SUCCESS);
	return (NULL);
}

static int	find_reps(long *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	check_validity(long *numbers, int count, int *valide)
{
	int	reps;

	reps = find_reps(numbers, count);
	*valide = reps;
}

long	*get_nbrs(char *str, int *count)
{
	int		i;
	char	**nb;
	long	*number;
	int		valide;

	i = 0;
	nb = ft_split(str, ' ');
	if (!nb)
		return (free(str), NULL);
	number = malloc((ft_array_len(nb) + 1) * sizeof(long));
	if (!number)
		return (free(str), ft_free_arr(nb), NULL);
	while (nb[i])
	{
		number[i] = ft_atoi(nb[i]);
		if (number[i++] == 9999999999)
			return (free(number), free(str), ft_free_arr(nb), msg_error(-1));
	}
	*count += ft_array_len(nb);
	check_validity(number, *count, &valide);
	free(str);
	ft_free_arr(nb);
	if (valide < 0)
		return (free(number), msg_error(valide));
	return (number);
}
