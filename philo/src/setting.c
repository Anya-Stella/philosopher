/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:25:54 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/03 14:09:18 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	set_config(int	argc, char **argv, t_config	*config);

int	set_info(int	argc, char** argv, t_info *info)
{
	if (set_config(argc, argv, info->config) == FAILURE)
		return (FAILURE);
	info->forks = (pthread_mutex_t	*)ft_calloc(info->config->num_philo, sizeof(pthread_mutex_t));
	if (!(info->forks))
		return (FAILURE);
	init_forks(info->forks, info->config->num_philo);
	return (SUCCESS);
}

static	int	set_config(int	argc, char **argv, t_config	*config)
{
	if (argc < 5)
		return (FAILURE);
	config->num_philo = ft_atoi(argv[1]);
	config->time_to_die = ft_atol(argv[2]);
	config->time_to_eat = ft_atol(argv[3]);
	config->time_to_sleep = ft_atol(argv[4]);
	if (argc == 5)
		config->num_min_eat = ft_atoi(argv[5]);
	else
		config->num_min_eat = -1;
	return (SUCCESS);
}

static	void	init_forks(pthread_mutex_t *forks, size_t num_philo)
{
	while (num_philo--)
	{
		pthread_mutex_init(forks, NULL);
		forks++;
	}
}
