/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:23:45 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/03 06:32:00 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	free_ifexist(const char *str, const char *ptr)
{
	if (str == ptr)
		free((char *)str);
	str = NULL;
	ptr = NULL;
}

char	*join(char const *str1, char const *str2)
{
	char		*join;
	char		*result;
	const char	*s;

	s = str1;
	if (!str1 || !str2)
		return (NULL);
	join = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 2);
	if (!join)
		return (free_ifexist(str1, s), NULL);
	result = join;
	while (*str1)
		*join++ = *str1++;
	*join++ = ' ';
	while (*str2)
		*join++ = *str2++;
	*join = '\0';
	return (free((char *)s), result);
}
