/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:52:31 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/01 17:10:34 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

typedef enum e_error_type
{
	NO_ERR,
	ARGS_ERR,
	PARSE_ERR,
	THREAD_ERR,
	MUTEX_ERR,
	MALLOC_ERR,
	MUST_EAT_ZERO,
}	t_error_type;

typedef enum e_finish_type
{
	ALIVE,
	DIE,
	EATALL,
}	t_finish_type;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	eat_time_event;
	pthread_mutex_t	alive_m;
	long long		start_time;
	int				alive;
	int				*fork_state;
}	t_data;

typedef struct s_info
{
	int		num_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	t_data	data;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	pthread_t		p_thread;
	int				eat_cnt;
	int				id;
	long long		last_eat_time;
	pthread_mutex_t	eat_num_event;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

t_error_type	init_data(t_info *info, t_philo **philo, int argc, char **argv);
void			*ft_calloc(size_t count, size_t size);
t_error_type	argument_check_valid(char **argv);
t_error_type	create_philosophers(t_philo *philo, t_data *data);
void			prt_error(char *str);
int				ft_atoi(const char *str);
long long		ft_gettime(void);
void			while_sleep(time_t time_to_wait);
t_finish_type	check_finish(t_philo *philo, int *id);
int				ft_printf(t_data *data, char *str, int id);
void			philodie(t_philo *philo, t_data *data, int i);
t_finish_type	check_die(t_data *data);
void			pick_up_forks(t_philo *philo);
void			pick_down_fork(t_philo *philo);

#endif
