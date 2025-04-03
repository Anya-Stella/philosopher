/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:52:23 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/03 13:57:57 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	long	border;
	int		lim;
	int		sign;
	int		digit;

	while (ft_isspace(*str))
		str++;
	sign = -2 * (*str == '-') + 1;
	str += (*str == '-' || *str == '+');
	result = 0;
	border = LONG_MAX / 10;
	lim = LONG_MAX % 10 + (1 - sign) / 2;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if ((result > border) || (result == border && digit > lim))
			return (-(sign + 1) / 2);
		result = (10 * result) + digit;
		str++;
	}
	return (sign * result);
}

int	ft_atoi(const char *str)
{
	return ((int) ft_atol(str));
}
