/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:45:47 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/03 16:55:17 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_and_print_info(t_info *info)
{
    // configやforksのNULLチェック
    if (!info || !info->config)
    {
        fprintf(stderr, "Error: info or info->config is NULL\n");
        return FAILURE;
    }
    if (!info->forks)
    {
        fprintf(stderr, "Error: info->forks is NULL\n");
        return FAILURE;
    }

    // 値が妥当かチェック
    if (info->config->num_philo <= 0)
    {
        fprintf(stderr, "Error: Invalid number_of_philosophers (%d)\n",
                info->config->num_philo);
        return FAILURE;
    }
    if (info->config->time_to_die <= 0)
    {
        fprintf(stderr, "Error: Invalid time_to_die (%ld)\n",
                info->config->time_to_die);
        return FAILURE;
    }
    if (info->config->time_to_eat <= 0)
    {
        fprintf(stderr, "Error: Invalid time_to_eat (%ld)\n",
                info->config->time_to_eat);
        return FAILURE;
    }
    if (info->config->time_to_sleep <= 0)
    {
        fprintf(stderr, "Error: Invalid time_to_sleep (%ld)\n",
                info->config->time_to_sleep);
        return FAILURE;
    }
    // num_min_eat は0以上なら特にエラーにはしない例
    // 必要ならチェックする

    // ここまでOKなら、値を表示してみる(デバッグ用)
    printf("=== Current Config ===\n");
    printf("num_philo    : %d\n",  info->config->num_philo);
    printf("time_to_die  : %ld\n", info->config->time_to_die);
    printf("time_to_eat  : %ld\n", info->config->time_to_eat);
    printf("time_to_sleep: %ld\n", info->config->time_to_sleep);
    printf("num_min_eat  : %d\n",  info->config->num_min_eat);
    printf("======================\n");

    return SUCCESS;
}








int	main(int ac, char **av)
{
	t_info		info;
	t_person	*persons;

	if (set_info(ac, av, &info) == FAILURE)
		return (1);
	persons = create_init_persons(&info);
	
	
	
	// 3:mutexを使って競合をなくす


	// test
	check_and_print_info(&info);

	// free
	free(info.config);
	free(info.forks);
	// persons
	return (0);
}


