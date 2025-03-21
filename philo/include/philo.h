/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:45:10 by tishihar          #+#    #+#             */
/*   Updated: 2025/03/21 17:59:52 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ---include---
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

// ---macro---

// ---structure---
typedef struct s_config
{
	int		num_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		num_min_eat;
} t_config;

typedef	struct s_person
{
	t_config	config;
	
	// 基本情報
	int				id;
	

	pthread_t		thread_id;


	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	





} t_person;











// ---functions---


