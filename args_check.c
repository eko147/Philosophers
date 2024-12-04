/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:41:08 by eunjiko           #+#    #+#             */
/*   Updated: 2023/04/29 18:49:28 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_arg_num(const char *str, int *idx)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (sign == -1)
		return (-1);
	*idx = i;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_atoi(const char	*str)
{
	int			idx;
	long long	res;

	idx = 0;
	res = 0;
	if (check_arg_num(str, &idx) == -1)
		return (-1);
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res = res * 10 + str[idx++] - '0';
		if (res > 2147483647)
			return (-1);
	}
	if (res == 0)
		return (-1);
	return (res);
}

t_error_type	argument_check_valid(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i++]) == -1)
			return (ARGS_ERR);
	}
	return (NO_ERR);
}
