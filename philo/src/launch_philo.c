/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:09:25 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/14 16:27:20 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
