
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:06:59 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/18 23:27:47 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads1(t_data *st)
{
	// pthread_mutex_t mutex;
	pthread_t	t;
	int			i;
	(void)st;
	// pthread_mutex_t forks[st->philo_n];
	// mutex forks[philo_n];
	// pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < st->philo_n)
	{
		pthread_create(&t, NULL, &philo_life, NULL);
		pthread_join(t, NULL);
		// puts("hello");
		i++;
	}
	// puts("hello");
}

void	*philo_life(void *arg)
{
	t_data	*st;
	// size_t	time1;
	// size_t	time2;

	st = (t_data *)arg;
	puts("hello from thread");
	// st = (t_data *)arg;
	// time1 = get_time(st)	;
	// ft_usleep(st->time_2_eat, st);
	// time2 = get_time(st);
	// printf("%zu\n", time2 - time1);
	return (0);
}

int	ft_usleep(useconds_t time, t_data *st)
{	
	size_t	start;
	start = get_time(st);
	while ((get_time(st) - start) < time)
		usleep(time / 10);
	return(0);
}

size_t	get_time(t_data *st)
{
	struct timeval	the_time;

	(void)st;
	gettimeofday(&the_time, NULL);
	return ((the_time.tv_sec * 1000));
}
