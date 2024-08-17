/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/17 21:22:34 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data *st)
{
	t_philo		*philo;
	// st->var = 0;

	philo = st->s_philo;
	pthread_mutex_init(&(st->node_mutex), NULL);
	pthread_mutex_init(&(st->flag_mutex), NULL);
	pthread_mutex_init(&(st->todie_mutex), NULL);
	st->die = 0;
	st->time = get_time();
	st->death = malloc (sizeof(pthread_mutex_t *));
	pthread_mutex_init((st->death), NULL); //could cause an error
	while (philo)
	{
		philo->last_meal = get_time();
		pthread_create(&(philo->id),NULL, routine, st);
		pthread_detach((philo->id)); //this for no waiting the threads
		philo = philo->next;
	}
	// pthread_mutex_lock(&(st->var_mutex));
	// st->var = 1;
	// pthread_mutex_unlock(&(st->var_mutex));
	wait_death(st); //add a var that should all the philos at the same time
}
