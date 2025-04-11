/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:02:42 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/11 17:48:48 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_dead(t_info	*info, int	id, long time_stamp)
{
	pthread_mutex_lock(&info->print_mutex);
	printf("%ld %i died\n", time_stamp, id);
	// pthread_mutex_unlock(&info->print_mutex);
}
