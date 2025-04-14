/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:52:23 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/14 17:36:24 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	set_start_ms(t_info *info)
{
	info->start_ms = get_current_time();
}

long	get_time_diff(long current_time, long start_time)
{
	return (current_time - start_time);
}

long	get_time_stamp(long start_time)
{
	return (get_time_diff(get_current_time(), start_time));
}
