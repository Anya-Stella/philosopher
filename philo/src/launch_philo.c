/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:09:25 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/15 13:32:28 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	launch_preparation(t_info *info);

// this func launch the philosopher simulation.
// At first, we establish start_ms, 
// and begin to simulate one after another.
void	philo_launch(t_person *persons, t_info *info)
{
	int			i;
	pthread_t	monitor_id;

	launch_preparation(info);
	pthread_create(&monitor_id, NULL, monitor_routine, info);
	i = 0;
	while (i < info->cfg.num_philo)
	{
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

static	void	launch_preparation(t_info *info)
{
	int	i;

	set_start_ms(info);
	i = 0;
	while (i < info->cfg.num_philo)
	{
		info->persons[i].last_eat_time = info->start_ms;
		i++;
	}
}
