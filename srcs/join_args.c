/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:44:17 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/04 05:01:00 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

static void	check_sp(char *str)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i++] == ' ')
		count++;
	if (count == ft_strlen(str))
		error_msg();
}

char	*join_args(char *argv[])
{
	int		i;
	char	*joined_args;

	i = 1;
	joined_args = ft_strdup("");
	if (!joined_args)
		return (NULL);
	while (argv[i])
	{
		if (!*argv[i])
		{
			free(joined_args);
			error_msg();
		}
		check_sp(argv[i]);
		joined_args = join(joined_args, argv[i]);
		if (!joined_args)
			exit(EXIT_FAILURE);
		i++;
	}
	return (joined_args);
}
