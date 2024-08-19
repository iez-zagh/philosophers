/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:03:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/19 12:22:51 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print(t_data *st, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&st->death);
	if (st->die)
		return (pthread_mutex_unlock(&st->death), 1);
	printf("%lu %d %s\n", get_time() - st->time, philo->index, msg);
	pthread_mutex_unlock(&st->death);
	return (0);
}

t_philo	*init_philo(t_data *st)
{
	t_philo	*philo;

	pthread_mutex_lock(&(st->node_mutex));
	philo = get_node(st->s_philo, st);
	pthread_mutex_unlock(&(st->node_mutex));
	if (philo && philo->index % 2 == 0)
		usleep(2000);
	return (philo);
}

int	sleep_think(t_data *st, t_philo *philo)
{
	if (print(st, philo, SLEEP))
		return (1);
	ft_usleep(st->time_2_sleep);
	if (print(st, philo, THINK))
		return (1);
	return (0);
}

void	*true_routine(t_data *st, t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->l_fork);
		if (print(st, philo, FORK))
			return (pthread_mutex_unlock(philo->l_fork), NULL);
		pthread_mutex_lock(philo->r_fork);
		if (print(st, philo, FORK))
			return (pthread_mutex_unlock(philo->l_fork),
				pthread_mutex_unlock(philo->r_fork), NULL);
		if (print(st, philo, EAT))
			return (pthread_mutex_unlock(philo->l_fork),
				pthread_mutex_unlock(philo->r_fork), NULL);
		pthread_mutex_lock(&(philo->last_meal_mutex));
		philo->last_meal = get_time();
		pthread_mutex_unlock(&(philo->last_meal_mutex));
		ft_usleep(st->time_2_eat);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_lock(&(philo->meals_n_mutex));
		philo->meals_n++;
		pthread_mutex_unlock(&(philo->meals_n_mutex));
		if (sleep_think(st, philo))
			return (NULL);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*st;

	st = (t_data *)arg;
	philo = init_philo(st);
	if (!true_routine(st, philo))
		return (NULL);
	return (NULL);
}
