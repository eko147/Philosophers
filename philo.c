/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:13:01 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/01 18:41:42 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	single_philo(t_philo *philo)
{
	ft_printf(&philo->info->data, "has taken a fork", philo->id);
	while_sleep(philo->info->time_to_die);
}

void	eating(t_philo *philo)
{
	pick_up_forks(philo);
	ft_printf(&philo->info->data, "is eating", philo->id);
	pthread_mutex_lock(&philo->eat_num_event);
	philo->last_eat_time = ft_gettime();
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->eat_num_event);
	while_sleep(philo->info->time_to_eat);
	pick_down_fork(philo);
}

void	*ft_thread(void *arg_philo)
{
	t_philo	*philo;

	philo = arg_philo;
	if (philo->id % 2)
		usleep(1000);
	if (philo->info->num_of_philos == 1)
	{
		single_philo(philo);
		return (NULL);
	}
	while (1)
	{
		if (check_die(&philo->info->data) == DIE)
			break ;
		eating(philo);
		if (philo->eat_cnt == philo->info->must_eat)
			break ;
		ft_printf(&(philo->info->data), "is sleeping", philo->id);
		while_sleep(philo->info->time_to_sleep);
		ft_printf(&(philo->info->data), "is thinking", philo->id);
	}
	return (NULL);
}

void	moniter_philos(t_philo *philo, t_data *data)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (1)
	{
		flag = check_finish(philo, &i);
		if (flag)
		{
			if (flag == DIE)
			{
				pthread_mutex_lock(&(data->print));
				printf("%lld %d %s\n", ft_gettime() - data->start_time, i + 1, \
				"died");
				pthread_mutex_lock(&(philo->info->data.alive_m));
				philo->info->data.alive = DIE;
				pthread_mutex_unlock(&(philo->info->data.alive_m));
				pthread_mutex_unlock(&(data->print));
			}
			break ;
		}
		usleep(256);
	}
}

t_error_type	create_philosophers(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	data->alive = ALIVE;
	data->start_time = ft_gettime();
	while (++i < philo->info->num_of_philos)
	{
		philo[i].last_eat_time = data->start_time;
		if (pthread_create(&(philo[i].p_thread), NULL, ft_thread, &(philo[i])))
		{
			prt_error("thread error\n");
			return (THREAD_ERR);
		}
	}
	moniter_philos(philo, data);
	i = 0;
	while (i < philo->info->num_of_philos)
		pthread_join(philo[i++].p_thread, NULL);
	return (NO_ERR);
}
