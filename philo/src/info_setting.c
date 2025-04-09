/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:16:27 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/09 13:04:10 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	init_cfg(int ac, char **av, t_info *info);
static	int		init_base_variable(t_info *info);
static	int		init_forks(t_info *info);
static	int		validate_arg(int ac, char **av);

int	init_info(int ac, char **av, t_info *info)
{
	if (validate_arg(ac, av) == FAILURE)
		return (FAILURE);
	init_cfg(ac, av, info);
	if (init_base_variable(info) == FAILURE)
		return (FAILURE);
	if (init_forks(info) == FAILURE)
	{
		pthread_mutex_destroy(&info->end_mutex);
		pthread_mutex_destroy(&info->print_mutex);
		return (FAILURE);
	}
	return (SUCCESS);
}

static	void	init_cfg(int ac, char **av, t_info *info)
{
	info->cfg.num_philo = ft_atoi(av[1]);
	info->cfg.time_to_die = ft_atol(av[2]);
	info->cfg.time_to_eat = ft_atol(av[3]);
	info->cfg.time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		info->cfg.num_min_eat = ft_atoi(av[5]);
	else
		info->cfg.num_min_eat = -1;
}

static	int	init_base_variable(t_info *info)
{
	info->start_ms = 0;
	info->finished = false;
	info->persons = NULL;

	if (pthread_mutex_init(&info->end_mutex, NULL))
		return (FAILURE);
	if (pthread_mutex_init(&info->print_mutex, NULL))
	{
		pthread_mutex_destroy(&info->end_mutex);
		return (FAILURE);
	}
	return (SUCCESS);
}

static	int	init_forks(t_info *info)
{
	int	i;

	info->forks = (pthread_mutex_t *)ft_calloc(info->cfg.num_philo, sizeof(pthread_mutex_t));
	if (!(info->forks))
		return (FAILURE);
	i = 0;
	while (i < info->cfg.num_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
		{
			destroy_forks(info, i);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static	int	validate_arg(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("error: missing argument.\n");
		return (FAILURE);
	}
	if (ft_atoi(av[1]) <= 0
		|| ft_atol(av[2]) <= 0
		|| ft_atol(av[3]) <= 0
		|| ft_atol(av[4]) <= 0
		|| (ac == 6 && ft_atoi(av[5]) < 0)
	)
	{
		printf("error: argument needs more than zero.\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
