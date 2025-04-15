/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_persons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:40:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/15 13:38:04 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	init_person(t_person *person, t_info *info, int id);

// this func initialize person structre, exept for thread id.
t_person	*create_init_persons(t_info	*info)
{
	int			i;
	t_person	*persons;

	persons = (t_person *)ft_calloc(info->cfg.num_philo, sizeof(t_person));
	if (!persons)
		return (NULL);
	i = 0;
	while (i < info->cfg.num_philo)
	{
		if (init_person(&persons[i], info, i + 1) == FAILURE)
		{
			destroy_eatmutexes(persons, i);
			return (NULL);
		}
		i++;
	}
	return (persons);
}

void	set_persons_to_info(t_info *info, t_person *persons)
{
	info->persons = persons;
}

static	int	init_person(t_person *person, t_info *info, int id)
{
	person->info = info;
	person->id = id;
	person->eat_count = 0;
	person->last_eat_time = 0;
	person->l_fork = &info->forks[id - 1];
	person->r_fork = &info->forks[id % info->cfg.num_philo];
	if (pthread_mutex_init(&person->eat_mutex, NULL))
		return (FAILURE);
	return (SUCCESS);
}
