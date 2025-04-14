/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:35 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/14 18:37:02 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	check_finished(t_info *info);

void	*monitor_routine(void *p)
{
	t_info *info;

	info = (t_info *)p;
	while (1)
	{
		if (check_finished(info))
		{
			pthread_mutex_lock(&info->end_mutex);
			info->finished = true;
			pthread_mutex_unlock(&info->end_mutex);
			break;
		}
		usleep(1000);
	}
	return (NULL);
}

static	int	check_finished(t_info *info)
{
	int 	i;
	bool	is_all_finished;

	i = 0;
	is_all_finished = true;
	while (i < info->cfg.num_philo)
	{
		pthread_mutex_lock(&info->eat_mutex);
		if (get_time_diff(get_current_time(), info->persons[i].last_eat_time) >= info->cfg.time_to_die)
		{
			print_dead(info, info->persons[i].id, get_time_diff(get_current_time(), info->persons[i].last_eat_time));
			pthread_mutex_unlock(&info->eat_mutex);
			return (1);
		}
		if (info->persons[i].eat_count < info->cfg.num_min_eat || info->cfg.num_min_eat < 0)
			is_all_finished = false;
		pthread_mutex_unlock(&info->eat_mutex);
		i++;
	}
	if (is_all_finished)
		return (1);
	return (0);
}
