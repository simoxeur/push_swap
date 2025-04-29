/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 04:12:04 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/03 03:17:20 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp_4moves(const char *line, const char *str)
{
	int	i;
	int	len_move;

	i = 0;
	len_move = ft_strlen(line) - 1;
	if (ft_strlen(str) != ft_strlen(line) - 1)
		return (1);
	while (line[i] && str[i] && line[i] == str[i] && i < len_move - 1)
		i++;
	return (((unsigned char)(line[i]) - (unsigned char)(str[i])));
}
