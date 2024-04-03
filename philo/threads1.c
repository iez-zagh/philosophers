/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:06:59 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/03 18:34:22 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads1(t_data *st)
{
	pthread_t	t;
	int			i;

	i = 19;
	while (i < st->philo_n)
	{
		if (pthread_create(&t, NULL, &philo_life, (void *)st))
			error(st, 3);
		if (pthread_join(t, NULL))
			error (st, 3);
		i++;
	}
}

void	*philo_life(void *arg)
{
	t_data			*st;
	size_t			time;
	size_t			time2;
	struct timeval	my_time;

	st = (t_data *)arg;
	gettimeofday(&my_time, NULL);
	time = ((my_time.tv_sec * 1000) + (my_time.tv_usec / 1000));
	// usleep(22000);
	gettimeofday(&my_time, NULL);
	time2 = ((my_time.tv_sec * 1000) + (my_time.tv_usec / 1000));
	// st = (t_data *)arg;
	printf("=%zu\n",time2 - time);
	// printf("%d\n", my_time.tv_usec);
	return (0);
}