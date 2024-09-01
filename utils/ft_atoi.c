/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 04:49:38 by mtalbi            #+#    #+#             */
/*   Updated: 2024/04/03 10:15:47 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static unsigned long long	ft_res(unsigned long long r, char *n, int i, int s)
{
	if (r == 0 && n[i] == '\0' && n[i - 1] != '0')
		return (9999999999);
	if (n[i] != 0 && (n[i] < 48 || n[i] > 57))
		return (9999999999);
	else
		r = r * s;
	return (r);
}

long	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					i;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] > 47 && str[i] < 58)
	{
		res = (res * 10) + (str[i] - 48);
		if (res >= 2147483648)
		{
			if (sign == -1 && res == 2147483648)
				return (-2147483648);
			return (9999999999);
		}
		i++;
	}
	return (ft_res(res, (char *)str, i, sign));
}
