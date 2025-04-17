/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:26:13 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/17 19:32:54 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	take_fork(t_person *person, int id);
static	void	put_down_fork(t_person *person,int id);
static	void	eat_meal(t_person *person, int id);
static	void	sleep_philo(t_person *person, int id);

// Q. Why we solve problem of philo_dead_lock by Even or Odd?
// A. if there are ABCD people order by
//    left handed, right handed, l.., r..., for short, lrlr.
//    they can't balancing both left-lr non-taking and right-lr non-taking.
//    so, n >= 4, noone can't take the fork is impossibles.
void	*philo_routine(void *p)
{
	t_person	*person;
	
	person = (t_person *)p;
	if (person->info->cfg.num_philo == 1)
	{
		How_to_die_a_lonely_philosopher(person);
		return (NULL);
	}
	while (1)
	{
		print_think(person->info, person->id, get_time_stamp(person->info->start_ms));
		pthread_mutex_lock(&person->info->end_mutex);
		if (person->info->finished)
		{
			pthread_mutex_unlock(&person->info->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&person->info->end_mutex);
		take_fork(person, person->id);
		eat_meal(person, person->id);
		put_down_fork(person, person->id);
		sleep_philo(person, person->id);
	}
	return (NULL);
}

static	void	take_fork(t_person *person, int id)
{
	long	start_ms;

	start_ms = person->info->start_ms;
	if (id % 2 == 1)
	{
		usleep(500);
		pthread_mutex_lock(person->l_fork);
		print_taken_fork(person->info, id, get_time_stamp(start_ms));
		pthread_mutex_lock(person->r_fork);
		print_taken_fork(person->info, id, get_time_stamp(start_ms));
	}
	else
	{
		pthread_mutex_lock(person->r_fork);
		print_taken_fork(person->info, id, get_time_stamp(start_ms));
		pthread_mutex_lock(person->l_fork);
		print_taken_fork(person->info, id, get_time_stamp(start_ms));
	}
}

static void	put_down_fork(t_person *person, int id)
{
	if (id % 2 == 1)
	{
		pthread_mutex_unlock(person->r_fork);
		pthread_mutex_unlock(person->l_fork);
	}
	else
	{
		pthread_mutex_unlock(person->l_fork);
		pthread_mutex_unlock(person->r_fork);
	}
}

static	void	eat_meal(t_person *person, int id)
{
	pthread_mutex_lock(&person->eat_mutex);
	person->last_eat_time = get_current_time();
	pthread_mutex_unlock(&person->eat_mutex);
	print_eat(person->info, id, get_time_stamp(person->info->start_ms));
	usleep(person->info->cfg.time_to_eat * 1000);
	pthread_mutex_lock(&person->eat_mutex);
	person->eat_count++;
	pthread_mutex_unlock(&person->eat_mutex);
}

static	void	sleep_philo(t_person *person, int id)
{
	print_sleep(person->info, id, get_time_stamp(person->info->start_ms));
	usleep(person->info->cfg.time_to_sleep * 1000);
}
