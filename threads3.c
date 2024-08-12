/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/12 18:10:54 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data *st)
{
	t_philo		*philo;
	pthread_t	id;

	philo = st->s_philo;
	pthread_mutex_lock(st->death);
	pthread_create(&id, NULL, wait_death, st);
	while (philo) //create a thread to wait for the death mutex
	{
		if (philo->index == (st->philo_n / 2))
			break;
		pthread_create(&(philo->id),NULL, routine, st);
		pthread_detach((philo->id)); //this for no waiting the threads
		philo = philo->next;
	}
	pthread_join(id, NULL);
}
