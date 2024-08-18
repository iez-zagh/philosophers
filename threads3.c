/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/18 22:07:09 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data *st)
{
	t_philo		*philo;
	int			i ;
	int			n;

	philo = st->s_philo;
	i = 0;
	n = st->philo_n;
	pthread_mutex_init(&(st->node_mutex), NULL);
	pthread_mutex_init(&(st->time_mutex), NULL);
	pthread_mutex_init(&(st->var_mutex), NULL);
	pthread_mutex_init(&(st->todie_mutex), NULL);
	pthread_mutex_init(&st->death, NULL);
	pthread_mutex_init(&st->hello_mutex, NULL);
	st->die = 0;
	st->f = 0;
	st->time = get_time();
	while (i++ < n)
	{
		// pthread_mutex_lock(&(philo->last_meal_mutex));
		philo->last_meal = get_time();
		// pthread_mutex_unlock(&(philo->last_meal_mutex));
		pthread_create(&(philo->id),NULL, routine, st);
		philo = philo->next;
	}
	// pthread_mutex_lock(&st->hello_mutex);
	// st->f = 1;
	// pthread_mutex_unlock(&st->hello_mutex);
	wait_death(st);
	i = 0;
	while (i++ < n)
	{
		pthread_join(philo->id, NULL);
		philo = philo->next;
	}
	ft_free(st, 1);
}

void	free_philo(t_philo *philo, int n, int flag)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	while (philo && i++ < n)
	{
		if (flag)
		{
			pthread_mutex_destroy(&(philo->index_mutex));
			pthread_mutex_destroy(&(philo->last_meal_mutex));
			pthread_mutex_destroy(&(philo->meals_n_mutex));
			pthread_mutex_destroy((philo->l_fork));
			pthread_mutex_destroy((philo->r_fork));
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

	i =  0;
	while (mutex && i++ < n)
	{
		pthread_mutex_destroy(&(mutex->mutex));
		tmp = mutex;
		mutex = mutex->next;
		free (tmp);
	}
}

void ft_free(t_data *st, int flag)
{
	free_mutex(st->mutexs, st->philo_n);
	if (!flag)
		return ;
	free_philo(st->s_philo, st->philo_n, flag);
	pthread_mutex_destroy(&(st->death));
	pthread_mutex_destroy(&(st->todie_mutex));
	pthread_mutex_destroy(&(st->time_mutex));
	pthread_mutex_destroy(&(st->node_mutex));
	pthread_mutex_destroy(&(st->var_mutex));
}
