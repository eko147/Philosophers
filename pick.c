/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:27:20 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/01 14:56:50 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_left_fork(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->l_fork);
		if (philo->info->data.fork_state[philo->id] == 0)
		{
			philo->info->data.fork_state[philo->id] = 1;
			ft_printf(&philo->info->data, "has taken a fork", philo->id);
			pthread_mutex_unlock(philo->l_fork);
			break ;
		}
		pthread_mutex_unlock(philo->l_fork);
		usleep(1000);
	}
}

void	pick_up_forks(t_philo *philo)
{
	int	r_fork;

	pick_up_left_fork(philo);
	r_fork = philo->id + 1 % philo->info->num_of_philos;
	while (1)
	{
		pthread_mutex_lock(philo->r_fork);
		if (philo->info->data.fork_state[r_fork] == 0)
		{
			philo->info->data.fork_state[r_fork] = 1;
			ft_printf(&philo->info->data, "has taken a fork", philo->id);
			pthread_mutex_unlock(philo->r_fork);
			break ;
		}
		pthread_mutex_unlock(philo->r_fork);
		usleep(1000);
	}
}

void	pick_down_fork(t_philo *philo)
{
	int	r_fork;

	r_fork = philo->id + 1 % philo->info->num_of_philos;
	pthread_mutex_lock(philo->l_fork);
	philo->info->data.fork_state[philo->id] = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	philo->info->data.fork_state[r_fork] = 0;
	pthread_mutex_unlock(philo->r_fork);
}
