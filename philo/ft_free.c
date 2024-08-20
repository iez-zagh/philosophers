/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:53:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/20 14:48:54 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo, int n, int flag)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	while (philo && i++ < n)
	{
		if (flag)
		{
			pthread_mutex_destroy(&(philo->last_meal_mutex));
			pthread_mutex_destroy(&(philo->meals_n_mutex));
		}
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
}

void	free_mutex(t_mutex *mutex, int n)
{
	int		i;
	t_mutex	*tmp;

	i = 0;
	while (mutex && i++ < n)
	{
		pthread_mutex_destroy(&(mutex->mutex));
		tmp = mutex;
		mutex = mutex->next;
		free (tmp);
	}
}

void	ft_free(t_data *st, int flag)
{
	free_mutex(st->mutexs, st->philo_n);
	if (!flag)
		return ;
	free_philo(st->s_philo, st->philo_n, flag);
	pthread_mutex_destroy(&(st->death));
	pthread_mutex_destroy(&(st->node_mutex));
	pthread_mutex_destroy(&(st->var_mutex));
}
