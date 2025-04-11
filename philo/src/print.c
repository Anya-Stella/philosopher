/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:02:42 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/11 18:24:19 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_dead(t_info	*info, int	id, long time_stamp)
{
	pthread_mutex_lock(&info->print_mutex);
	printf("%ld %i died\n", time_stamp, id);
	// pthread_mutex_unlock(&info->print_mutex);
}

void	print_taken_fork(t_info	*info, int	id, long time_stamp)
{
	pthread_mutex_lock(&info->print_mutex);
	printf("%ld %i taken a fork\n", time_stamp, id);
	pthread_mutex_unlock(&info->print_mutex);
}

void	print_eat(t_info	*info, int	id, long time_stamp)
{
	pthread_mutex_lock(&info->print_mutex);
	printf("%ld %i is eatingk\n", time_stamp, id);
	pthread_mutex_unlock(&info->print_mutex);
}

void	print_sleep(t_info	*info, int	id, long time_stamp)
{
	pthread_mutex_lock(&info->print_mutex);
	printf("%ld %i is sleeping\n", time_stamp, id);
	pthread_mutex_unlock(&info->print_mutex);
}

void	print_think(t_info	*info, int	id, long time_stamp)
{
	pthread_mutex_lock(&info->print_mutex);
	printf("%ld %i is thinking\n", time_stamp, id);
	pthread_mutex_unlock(&info->print_mutex);
}

