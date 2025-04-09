/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:23:49 by tishihar          #+#    #+#             */
/*   Updated: 2025/04/09 15:24:10 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void print_cfg(const t_config *cfg)
{
    printf("cfg -------------\n");
    printf("  num_philo     : %d\n",  cfg->num_philo);
    printf("  time_to_die   : %ld\n", cfg->time_to_die);
    printf("  time_to_eat   : %ld\n", cfg->time_to_eat);
    printf("  time_to_sleep : %ld\n", cfg->time_to_sleep);
    printf("  num_min_eat   : %d\n",  cfg->num_min_eat);
}

static void print_person(const t_person *p)
{
    printf("person #%d ------\n", p->id);
    printf("  thread_id     : %lu\n", (unsigned long)p->thread_id);
    printf("  eat_count     : %d\n",  p->eat_count);
    printf("  last_eat_time : %ld\n", p->last_eat_time);
    printf("  l_fork addr   : %p\n",  (void *)p->l_fork);
    printf("  r_fork addr   : %p\n",  (void *)p->r_fork);
}

void dump_info(const t_info *info)
{
    int i;

    if (!info)
        return ;
    printf("==== dump_info ====\n");
    print_cfg(&info->cfg);
    printf("info ------------\n");
    printf("  start_ms      : %ld\n", info->start_ms);
    printf("  finished      : %d\n",  info->finished);
    printf("  forks addr    : %p\n",  (void *)info->forks);
    printf("  persons addr  : %p\n",  (void *)info->persons);
    printf("  end_mutex ptr : %p\n",  (void *)&info->end_mutex);
    printf("  print_mutex ptr: %p\n", (void *)&info->print_mutex);
    if (!info->persons)
    {
        printf("  (persons == NULL)\n");
        return ;
    }
    i = 0;
    while (i < info->cfg.num_philo)
    {
        print_person(&info->persons[i]);
        i++;
    }
    printf("===================\n");
}

