/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:25:54 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/03 16:19:32 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	set_config(int	argc, char **argv, t_info *info);
static	int	set_forks(t_info *info, size_t num_philo);

int	set_info(int	argc, char** argv, t_info *info)
{
	if (argc != 5 && argc != 6)
	{
		printf("error: missing argument.\n");
		return (FAILURE);
	}
	if (set_config(argc, argv, info) == FAILURE)
	{
		printf("error: set_config failed.\n");
		return (FAILURE);
	}
	if (set_forks(info, info->config->num_philo) == FAILURE)
	{
		printf("error: set_forks failed.\n");
		free(info->config);
		return (FAILURE);
	}
	return (SUCCESS);
}

static	int	set_config(int	argc, char **argv, t_info *info)
{
	info->config = (t_config *)ft_calloc(1, sizeof(t_config));
	if (!(info->config))
		return (FAILURE);
	info->config->num_philo = ft_atoi(argv[1]);
	info->config->time_to_die = ft_atol(argv[2]);
	info->config->time_to_eat = ft_atol(argv[3]);
	info->config->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		info->config->num_min_eat = ft_atoi(argv[5]);
	else
		info->config->num_min_eat = -1;
	return (SUCCESS);
}

static	int	set_forks(t_info *info, size_t num_philo)
{
	int	i;

	info->forks = (pthread_mutex_t *)ft_calloc(info->config->num_philo, sizeof(pthread_mutex_t));
	if (!(info->forks))
		return (FAILURE);
	i = 0;
	while (i < (int)num_philo)
	{
		pthread_mutex_init(&(info->forks[i]), NULL);
		i++;
	}
	return (SUCCESS);
}
