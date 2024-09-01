/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:32:23 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/19 15:30:47 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		ft_strcmp_4moves(const char *line, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atoi(const char *str);
char	*join(char const *str1, char const *str2);
int		ft_array_len(char *argv[]);
void	ft_free_arr(char **str);
void	error_msg(void);

#endif