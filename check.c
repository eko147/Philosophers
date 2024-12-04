/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:17:20 by meliesf           #+#    #+#             */
/*   Updated: 2023/05/01 14:49:05 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_finish_type	check_die(t_data *data)
{
	pthread_mutex_lock(&data->alive_m);
	if (data->alive == DIE)
	{
		pthread_mutex_unlock(&data->alive_m);
		return (DIE);
	}
	pthread_mutex_unlock(&data->alive_m);
	return (0);
}

t_finish_type	check_finish(t_philo *philo, int *id)
{
	int	i;
	int	alleatcnt;

	i = -1;
	alleatcnt = 0;
	while (++i < philo->info->num_of_philos)
	{
		if (philo->info->must_eat != 0)
		{
			pthread_mutex_lock(&(philo[i].eat_num_event));
			alleatcnt += philo[i].eat_cnt;
			pthread_mutex_unlock(&(philo[i].eat_num_event));
			if (alleatcnt == philo->info->must_eat * philo->info->num_of_philos)
				return (EATALL);
		}
		pthread_mutex_lock(&(philo[i].eat_num_event));
		if (ft_gettime() - philo[i].last_eat_time > philo->info->time_to_die)
		{
			pthread_mutex_unlock(&(philo[i].eat_num_event));
			*id = i;
			return (DIE);
		}
		pthread_mutex_unlock(&(philo[i].eat_num_event));
	}
	return (ALIVE);
}
