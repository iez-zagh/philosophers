/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/14 11:28:35 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data *st)
{
	t_philo		*philo;
	pthread_t	id;

	philo = st->s_philo;
	pthread_mutex_init(&(st->node_mutex), NULL);
	st->die = 0;
	st->time = get_time();
	pthread_mutex_init(&(st->death), NULL); //this is error
	while (philo)
	{
		if (!(philo->index % 2)) //need ot improve this better
			usleep(800);
		pthread_create(&(philo->id),NULL, routine, st);
		pthread_detach((philo->id)); //this for no waiting the threads
		philo = philo->next;
	}
	pthread_create(&id, NULL, wait_death, st);
	pthread_join(id, NULL);
}
