/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:03:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/10 14:00:53 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


t_mutex	*get_last(t_mutex *philo)
{
	if (!philo)
		return (NULL);
	while (philo->next)
		philo = philo->next;
	return (philo);
}

void	add_back(t_mutex **philo, t_mutex *new)
{
	if (!*philo)
		*philo = new;
	else
	{
		get_last(*philo)->next = new;
		new->next = NULL;
	}
}

void	routine(t_data *st)
{
	(void)st;
	puts("hello from thread");
}

t_mutex *create_mutex(int i)
{
	int		j;
	t_mutex	*mutex1;
	t_mutex	*new;

	j = 0;
	mutex1 = NULL;
	while (j < i)
	{
		new = malloc(sizeof(t_mutex));
		pthread_mutex_init(&(new->mutex), NULL);
		add_back(&mutex1, new);
		j++;
	}
	return (mutex1);
}


void	initializing_threads(t_data *st)
{
	t_mutex	*mutex;

	mutex = create_mutex(st->philo_n);
	st->mutexs = mutex;
	// int		i;
	// t_philo	*philo;

	// i = 0;
	// philo = NULL;
	// while (i < st->philo_n)
	// {
		
	// }
}
