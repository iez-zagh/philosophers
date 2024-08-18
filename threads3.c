/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/18 15:17:45 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data *st)
{
	t_philo		*philo;
	int			i = 0;
	int			n = st->philo_n;

	philo = st->s_philo;
	pthread_mutex_init(&(st->node_mutex), NULL);
	pthread_mutex_init(&(st->time_mutex), NULL);
	pthread_mutex_init(&(st->var_mutex), NULL);
	pthread_mutex_init(&(st->todie_mutex), NULL);
	pthread_mutex_init(&st->death, NULL);
	pthread_mutex_lock(&st->death);
	st->die = 0;
	pthread_mutex_unlock(&st->death);
	st->time = get_time();
	while (i++ < n)
	{
		pthread_mutex_lock(&(philo->last_meal_mutex));
		philo->last_meal = get_time();
		pthread_mutex_unlock(&(philo->last_meal_mutex));
		pthread_create(&(philo->id),NULL, routine, st);
		// pthread_detach((philo->id)); //this for no waiting the threads
		philo = philo->next;
	}
	wait_death(st);
	i = 0;
	while (i++ < n)
	{
		pthread_join(philo->id, NULL);
		philo = philo->next;
	}
	ft_free(st);
}

void	free_philo(t_philo *philo, int n)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	while (i++ < n)
	{
		pthread_mutex_destroy(&(philo->index_mutex));
		pthread_mutex_destroy(&(philo->last_meal_mutex));
		pthread_mutex_destroy(&(philo->meals_n_mutex));
		pthread_mutex_destroy((philo->l_fork));
		pthread_mutex_destroy((philo->r_fork));
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
	while (i++ < n) //check the i
	{
		pthread_mutex_destroy(&(mutex->mutex));
		tmp = mutex;
		mutex = mutex->next;
		free (tmp);
	}
}

void ft_free(t_data *st)
{
	pthread_mutex_destroy(&(st->death));
	free_mutex(st->mutexs, st->philo_n);
	free_philo(st->s_philo, st->philo_n);
	pthread_mutex_destroy(&(st->todie_mutex));
	pthread_mutex_destroy(&(st->time_mutex));
	pthread_mutex_destroy(&(st->node_mutex));
	pthread_mutex_destroy(&(st->var_mutex));
}
