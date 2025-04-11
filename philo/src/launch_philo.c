/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:09:25 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/11 15:31:18 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	*philo_routine(void *person);
static	void	*monitor_routine(void *person);
static	int	check_persons_die(t_info *info);

// this func launch the philosopher simulation.
// At first, we establish start_ms, 
// and begin to simulate one after another.
void	philo_launch(t_person *persons, t_info *info)
{
	int			i;
	pthread_t	monitor_id;

	set_start_ms(info);
	pthread_create(&monitor_id, NULL, monitor_routine, info);
	i = 0;
	while (i < info->cfg.num_philo)
	{
		// こいつらは呼ばれた順に食べていく
		pthread_create(&persons[i].thread_id, NULL, philo_routine, &persons[i]);
		i++;
	}
	pthread_join(monitor_id, NULL);
	i = 0;
	while (i < info->cfg.num_philo)
	{
		pthread_join(persons[i].thread_id, NULL);
		i++;
	}
}

// start_msでスレッド内関数が起動するルーティン関数つくる
// 誰かが死んだとき、その後シュミレーションは終了する

static	void	*philo_routine(void *p)
{
	
}

static	void	*monitor_routine(void *p)
{
	t_info *info;

	info = p;
	while (1)
	{
		if (check_persons_die(info))
		{
			pthread_mutex_lock(&info->end_mutex);
			info->finished = true;
			pthread_mutex_unlock(&info->end_mutex);
			break;
		}
		usleep(100);
	}
	return (NULL);
}

static	int	check_persons_die(t_info *info)
{
	int i;

	i = 0;
	while (i < info->cfg.num_philo)
	{
		pthread_mutex_lock(&info->last_eat_mutex);
		if (get_time_diff(get_current_time(), info->persons[i].last_eat_time) >= info->cfg.time_to_die)
		{
			// pthread_mutex_lock(&info->print_mutex);
			print_dead(info, info->persons[i].id, get_time_diff(get_current_time(), info->persons[i].last_eat_time));
			return (1);
		}
		pthread_mutex_unlock(&info->last_eat_mutex);
		i++;
	}
	return (0);
}
