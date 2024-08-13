/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:03:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/13 21:52:24 by iez-zagh         ###   ########.fr       */
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
t_philo	*get_node(t_philo *philo)
{
	static int	i = 0;
	int			j;

	j = 0;
	while (j < i)
	{
		philo = philo->next;
		j++;
	}
	i++;
	return (philo);

}

void print(t_data *st, t_philo *philo, char *msg)
{
	printf("%lld  %d   %s\n", get_time() - st->time,philo->index, msg);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*st;
	
	st = (t_data *)arg;
	pthread_mutex_lock(&(st->node_mutex));
	philo = get_node(st->s_philo);
	pthread_mutex_unlock(&(st->node_mutex));
	while (1)
	{
		// printf("index=%d]] l == %p r == %p\n", philo->index, philo->l_fork, philo->r_fork);
		// return (NULL);
		// pthread_mutex_lock(&(st->death));
		pthread_mutex_lock(philo->l_fork);
		// printf("%lld  %d   has taken a fork\n", get_time() - st->time,philo->index);
		print(st, philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		printf("%lld  %d   has taken a fork\n", get_time() - st->time, philo->index);
		printf("%lld  %d   is eating\n", get_time() - st->time, philo->index);
		philo->last_meal = get_time();
		ft_usleep(st->time_2_eat);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		printf("%lld  %d   is sleeping\n", get_time() - st->time, philo->index);
		ft_usleep(st->time_2_sleep);
		printf("%lld  %d   is thinking\n", get_time() - st->time, philo->index);
		// pthread_mutex_unlock(&(st->death));
	}
	return (NULL);
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
	initialze_philo(st);
	create_threads(st);
}

void	*wait_death(void *arg)
{
	t_data	*st;
	t_philo	*philo;

	st = (t_data *)arg;
	philo = st->s_philo;
	while (philo)
	{
		size_t time = (get_time() - philo->last_meal);
		if (time > (size_t)st->time_2_die)
		{
			// printf("%llu]]\n", philo->last_meal);
			// printf("%zu]]\n", time);
			// pthread_mutex_lock(&(st->death));
			printf("%lld  %d   died\n",get_time() - st->time, philo->index);
			return (NULL);
		}
		if (!philo->next)
			philo = st->s_philo;
		else
		philo = philo->next;
	}
	return (NULL);
}
