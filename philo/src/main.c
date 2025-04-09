/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:45:47 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/09 15:39:20 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info		info;
	t_person	*persons;

	if (init_info(ac, av, &info) == FAILURE)
		return (1);
	persons = create_init_persons(&info);
	if (!persons)
	{
		destroy_info(&info);
		return (1);
	}
	set_persons_to_info(&info, persons);
	
	// スレッドをpersonsにたいしてつくってつまりrunする
	// philo_launch();
	
	
	
	
	// test
	// dump_info(&info);

	
	// destroy(info, persons)
	return (0);
}


