/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:45:10 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/17 17:22:50 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// ---include---
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdint.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// ---macro---
# define SUCCESS 0
# define FAILURE 1

// ---structure---
typedef struct s_info	t_info;
typedef struct s_person	t_person;

typedef struct s_config
{
	int				num_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				num_min_eat;
}	t_config;

// explanation of info mutex;
// eat_mutex: this protects the eat_count, and last_eat_time;
// end_mutex: this protects the finished flag;
// print_mutex: this protects the using printf.
typedef struct s_info
{
	t_config		cfg;
	long			start_ms;
	bool			finished;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	t_person		*persons;
}	t_info;

typedef struct s_person
{
	pthread_t		thread_id;
	t_info			*info;
	int				id;
	int				eat_count;
	long			last_eat_time;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_person;

// ---functions---
// setting
int			init_info(int ac, char **av, t_info *info);
void		set_persons_to_info(t_info *info, t_person *persons);

// persons
t_person	*create_init_persons(t_info	*info);

// launch
void		philo_launch(t_person *persons, t_info *info);
void		*monitor_routine(void *p);
void		*philo_routine(void *p);

// destroy
void		destroy_info(t_info *info);
void		destroy_persons(t_person *persons);
void		destroy_forks(t_info *info, int destroy_forks_size);
void		destroy_eatmutexes(t_person *persons, int destroy_mutex_size);
long		get_time_diff(long current_time, long start_time);

// time
long		get_current_time(void);
void		set_start_ms(t_info *info);
long		get_time_diff(long current_time, long start_time);
long		get_time_stamp(long start_time);

// print
void		print_dead(t_info *info, int id, long time_stamp);
void		print_taken_fork(t_info *info, int id, long time_stamp);
void		print_eat(t_info *info, int id, long time_stamp);
void		print_sleep(t_info *info, int id, long time_stamp);
void		print_think(t_info *info, int id, long time_stamp);

// utils
void		*ft_calloc(size_t count, size_t size);
long		ft_atol(const char *str);
int			ft_atoi(const char *str);

// other
void	How_to_die_a_lonely_philosopher(t_person *person);

//test
// void		dump_info(const t_info *info);

#endif