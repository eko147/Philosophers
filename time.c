/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:21:04 by meliesf           #+#    #+#             */
/*   Updated: 2023/05/01 19:14:31 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	while_sleep(time_t time_to_wait)
{
	long long	start_time;

	start_time = ft_gettime();
	while (ft_gettime() - start_time < time_to_wait)
		usleep(1000);
}
