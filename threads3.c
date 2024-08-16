/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/16 16:50:58 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data *st)
{
	t_philo		*philo;

	philo = st->s_philo;
	pthread_mutex_init(&(st->node_mutex), NULL);
	// pthread_mutex_init(&(st->flag_mutex), NULL);
	pthread_mutex_init(&(st->todie_mutex), NULL);
	st->die = 0;
	st->time = get_time();
	pthread_mutex_init(&(st->death), NULL); //could cause an error
	while (philo)
	{
		philo->last_meal = get_time();
		pthread_create(&(philo->id),NULL, routine, st);
		pthread_detach((philo->id)); //this for no waiting the threads
		if (philo->index == 1 || !(philo->index % 2)) //need ot improve this better
		{
			// printf("%d]]\n", philo->index);
			usleep(1000);
			// puts("hello");
		}
		philo = philo->next;
	}
	wait_death(st);
}
