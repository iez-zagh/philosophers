/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:03:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/12 20:15:25 by iez-zagh         ###   ########.fr       */
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
void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*st;
	// size_t	time;

	
	st = (t_data *)arg;
	philo = get_node(st->s_philo);
	while (1 && st->flag)
	{
		// puts("inside of a thread");
		pthread_mutex_lock(philo->l_fork);
		printf("%d has taken a fork\n", philo->index);
		pthread_mutex_lock(philo->r_fork);
		printf("%d has taken a fork\n", philo->index);
		printf("%d is eating\n", philo->index);
		//time to eat
		//time to eat
		printf("%d is sleeping\n", philo->index);
		//time to sleep
		printf("%d is thinking\n", philo->index);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		usleep(50000);
		pthread_mutex_unlock(st->death);
		// pthread_mutex_unlock()
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
	t_mutex			*mutex;

	mutex = create_mutex(st->philo_n);
	st->mutexs = mutex;
	initialze_philo(st);
	create_threads(st);
}

void	*wait_death(void *arg)
{
	t_data	*st;

	st = (t_data *)arg;
	// while (1)
	st->flag = 1;
	pthread_mutex_lock(st->death);
	st->flag = 0;
	write(1, "died\n", 5);
	return (NULL);
}
