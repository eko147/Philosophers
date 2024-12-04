/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:16:11 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/01 19:24:24 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "unistd.h"

void	free_all(t_philo *philo, t_info info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info.data.print);
	pthread_mutex_destroy(&info.data.eat_time_event);
	pthread_mutex_destroy(&info.data.alive_m);
	free(info.data.fork_state);
	while (i < info.num_of_philos)
	{
		pthread_mutex_destroy(&info.data.forks[i]);
		pthread_mutex_destroy(&philo[i].eat_num_event);
		i++;
	}
	free(info.data.forks);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	if (init_data(&info, &philo, argc, argv) != NO_ERR)
		return (-1);
	create_philosophers(philo, &info.data);
	free_all(philo, info);
	return (0);
}
