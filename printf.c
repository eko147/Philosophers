/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:17:01 by eunjiko           #+#    #+#             */
/*   Updated: 2023/04/29 21:21:41 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_printf(t_data *data, char *str, int id)
{
	pthread_mutex_lock(&(data->print));
	pthread_mutex_lock(&(data->alive_m));
	if (data->alive == DIE)
	{
		pthread_mutex_unlock(&(data->alive_m));
		pthread_mutex_unlock(&(data->print));
		return (0);
	}
	pthread_mutex_unlock(&(data->alive_m));
	printf("%lld %d %s\n", ft_gettime() - data->start_time, id + 1, str);
	pthread_mutex_unlock(&(data->print));
	return (1);
}
