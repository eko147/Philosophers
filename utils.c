/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:04:14 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/01 18:05:42 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	prt_error(char *str)
{
	write(2, str, ft_strlen(str));
	return ;
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ss;
	int				i;

	ss = s;
	i = 0;
	while (n)
	{
		ss[i++] = 0;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = (void *)malloc(size * count);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, (count * size));
	return (tmp);
}
