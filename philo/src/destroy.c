/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:41:14 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/11 17:35:25 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// info系
void	destroy_info(t_info *info)
{
	destroy_forks(info, info->cfg.num_philo);
	pthread_mutex_destroy(&info->end_mutex);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
}

void	destroy_forks(t_info *info, int destroy_forks_size)
{
	int	i;

	i = 0;
	while (i < destroy_forks_size)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	free(info->forks);
	info->forks = NULL;
}
