/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:56:00 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/09 16:44:52 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	ft_isspace(int c);
static	int	ft_isdigit(int c);

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

int		ft_atoi(const char *str)
{
	return ((int) ft_atol(str));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	memset(p, 0, count * size);
	return (p);
}

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

static	int	ft_isdigit(int c)
{
	return (48 <= c && c <= 57);
}
