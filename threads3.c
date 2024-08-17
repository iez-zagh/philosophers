/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/18 00:27:31 by iez-zagh         ###   ########.fr       */
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
	pthread_mutex_init(&(st->flag_mutex), NULL);
	pthread_mutex_init(&(st->todie_mutex), NULL);
	st->die = 0;
	st->time = get_time();
	st->death = malloc (sizeof(pthread_mutex_t *));
	pthread_mutex_init((st->death), NULL); //could cause an error
	while (i < n)
	{
		philo->last_meal = get_time();
		pthread_create(&(philo->id),NULL, routine, st);
		pthread_detach((philo->id)); //this for no waiting the threads
		philo = philo->next;
		i++;
	}
	wait_death(st); //add a var that should all the philos at the same time
	ft_free(st);
}

void	free_philo(t_philo *philo, int n)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&(philo->index_mutex));
		pthread_mutex_destroy(&(philo->last_meal_mutex));
		pthread_mutex_destroy(&(philo->meals_n_mutex));
		pthread_mutex_destroy((philo->l_fork));
		pthread_mutex_destroy((philo->r_fork));
		tmp = philo;
		philo = philo->next;
		free(tmp);
		i++;
	}
}

void	free_mutex(t_mutex *mutex, int n)
{
	int		i;
	t_mutex	*tmp;

	i =  0;
	while (i < n)
	{
		pthread_mutex_destroy(&(mutex->mutex));
		tmp = mutex;
		mutex = mutex->next;
		free (tmp);
		i++;
	}
}

void ft_free(t_data *st)
{
	free_mutex(st->mutexs, st->philo_n);
	free_philo(st->s_philo, st->philo_n);
	pthread_mutex_destroy((st->death));
	pthread_mutex_destroy(&(st->todie_mutex));
	free(st->death);
}
