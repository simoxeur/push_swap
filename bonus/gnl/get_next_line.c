/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:46:30 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/19 15:32:00 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_new_collect(char *str)
{
	char	*new_str;
	int		i;
	size_t	len;

	if (!str || !*str)
		return (NULL);
	new_str = NULL;
	i = 0;
	len = ft_strlen_gnl(str, '\n') + 1;
	if (ft_check_nl(str) == 0 || str[len] == '\0')
		return (NULL);
	new_str = (char *)malloc((ft_strlen_gnl(str, '\0') - len + (size_t)1));
	if (!new_str)
		return (NULL);
	while (str[len] != '\0')
	{
		new_str[i] = str[len];
		i++;
		len++;
	}
	new_str[i] = '\0';
	if (!*new_str)
		return (free(new_str), NULL);
	return (new_str);
}

static char	*ft_get_line(int fd, char *buffer)
{
	static char	*collect;
	char		*line;
	char		*tmp;
	ssize_t		readed;
	size_t		len;

	readed = 1;
	line = NULL;
	while (readed > 0 && ft_check_nl(collect) == 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
			return (free(collect), collect = NULL, NULL);
		buffer[readed] = '\0';
		collect = ft_strnjoin(collect, buffer, readed);
	}
	len = ft_strlen_gnl(collect, '\n') + 1;
	if (ft_check_nl(collect) == 0)
		len = ft_strlen_gnl(collect, '\0');
	line = ft_strnjoin(line, collect, len);
	tmp = collect;
	collect = ft_new_collect(collect);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + (size_t)1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	line = ft_get_line(fd, buffer);
	free(buffer);
	if (!line || *line == '\0')
		return (free(line), NULL);
	return (line);
}
