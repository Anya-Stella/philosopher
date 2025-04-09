/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:45:47 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/09 14:19:32 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info		info;
	t_person	*persons;

	if (set_info(ac, av, &info) == FAILURE)
		return (1);
	persons = create_init_persons(&info);
	if (!persons)
	{
		destroy_info(&info);
		return (1);
	}
	set_persons_to_info(&info, persons);
	
	// スレッドをpersonsにたいしてつくってつまりrunする
	
	


	// test

	
	// destroy(info, persons)
	return (0);
}


