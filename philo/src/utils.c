/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:56:00 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/02 16:02:41 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	*ft_memset(void *b, int c, size_t len);

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, count * size);
	return (p);
}

static	void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len--)
		*(p++) = (unsigned char)c;
	return (b);
}
