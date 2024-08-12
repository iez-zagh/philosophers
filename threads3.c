/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/12 14:13:01 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data *st)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = st->s_philo;
	while (i < (st->philo_n / 2))
	{
		pthread_create(&(philo->id),NULL, routine, philo);
		// if (i != 3)
		// pthread_detach((philo->id));
		philo = philo->next;
		i++;
	}
	pthread_join(philo->id, NULL);
	sleep(5);
}
