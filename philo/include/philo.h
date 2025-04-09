/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:45:10 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/09 13:03:44 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// ---include---
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

// ---macro---
#define SUCCESS 0
#define FAILURE 1


// ---structure---

typedef struct s_config
{
	int		num_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		num_min_eat;
} t_config;

typedef	struct s_info
{
	t_config		cfg;
	long			start_ms;
	bool			finished;
	
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	print_mutex;
	
	pthread_mutex_t	*forks;

	t_person		*persons;
} t_info;

typedef	struct s_person
{
	t_info			*info;
	int				id;
	pthread_t		thread_id;
	int				eat_count;
	long			last_eat_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
} t_person;


// ---functions---
// setting
int	set_info(int	argc, char** argv, t_info *info);

// utils
void	*ft_calloc(size_t count, size_t size);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);

#endif