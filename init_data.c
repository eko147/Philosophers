/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:58:06 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/01 18:37:43 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error_type	parse_args(t_info *info, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (ARGS_ERR);
	if (argument_check_valid(argv) != ARGS_ERR)
	{
		memset(info, 0, sizeof(t_info));
		info->num_of_philos = ft_atoi(argv[1]);
		info->time_to_die = ft_atoi(argv[2]);
		info->time_to_eat = ft_atoi(argv[3]);
		info->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			info->must_eat = ft_atoi(argv[5]);
		return (NO_ERR);
	}
	return (ARGS_ERR);
}

t_error_type	init_mutex(t_data *data, int num_of_philos)
{
	int	i;

	if (pthread_mutex_init(&data->print, NULL))
		return (MUTEX_ERR);
	if (pthread_mutex_init(&data->alive_m, NULL))
		return (MUTEX_ERR);
	data->forks = ft_calloc(num_of_philos, sizeof(pthread_mutex_t));
	i = 0;
	while (i < num_of_philos)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (MUTEX_ERR);
		i++;
	}
	return (NO_ERR);
}

t_error_type	init_philo(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	*philo = ft_calloc(info->num_of_philos, sizeof(t_philo));
	if (!*philo)
		return (MALLOC_ERR);
	info->data.fork_state = ft_calloc(info->num_of_philos, sizeof(int));
	if (!info->data.fork_state)
		return (MALLOC_ERR);
	while (i < info->num_of_philos)
	{
		(*philo)[i].l_fork = &info->data.forks[i];
		(*philo)[i].r_fork = &info->data.forks[(i + 1) % info->num_of_philos];
		(*philo)[i].id = i;
		(*philo)[i].info = info;
		i++;
	}
	return (NO_ERR);
}

t_error_type	init_data(t_info *info, t_philo **philo, int argc, char **argv)
{
	if (parse_args(info, argc, argv) == ARGS_ERR)
	{
		prt_error("parse_error\n");
		return (ARGS_ERR);
	}
	if (init_mutex(&info->data, info->num_of_philos) != NO_ERR)
	{
		prt_error("mutex_error\n");
		return (MUTEX_ERR);
	}
	if (init_philo(philo, info) == MALLOC_ERR)
	{
		prt_error("malloc_error\n");
		return (MALLOC_ERR);
	}
	return (NO_ERR);
}
