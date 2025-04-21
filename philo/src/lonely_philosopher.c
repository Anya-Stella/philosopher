/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:12:35 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/21 18:01:21 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	how_to_die_a_lonely_philosopher(t_person *person)
{
	pthread_mutex_lock(&person->info->print_mutex);
	printf("%d %i has taken a fork\n", 0, person->id);
	pthread_mutex_unlock(&person->info->print_mutex);
}
