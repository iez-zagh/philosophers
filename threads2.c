/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:03:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/14 12:58:37 by iez-zagh         ###   ########.fr       */
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
	pthread_mutex_lock(&(st->death));
	if (st->die)
		return ;
	printf("%lld  %d   %s\n", get_time() - st->time,philo->index, msg);
	pthread_mutex_unlock(&(st->death));
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
		pthread_mutex_lock(philo->l_fork);
		print(st, philo, FORK);
		pthread_mutex_lock(philo->r_fork);
		print(st, philo, FORK);
		philo->last_meal = get_time();
		print(st, philo, EAT);
		ft_usleep(st->time_2_eat);
		philo->meals_n++;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		print(st, philo, SLEEP);
		ft_usleep(st->time_2_sleep);
		print(st, philo, THINK);
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

int	check_meals(t_philo *philo, int n)
{
	while (philo)
	{
		if (philo->meals_n < n)
			return (1);
		philo = philo->next;			
	}
	return (0);
}
void	*wait_death(void *arg)
{
	t_data	*st;
	t_philo	*philo;

	st = (t_data *)arg;
	philo = st->s_philo;
	while (philo)
	{
		if (st->eat_n != -1 && check_meals(st->s_philo, st->eat_n))
			return (NULL);
		if (get_time() - philo->last_meal > (size_t)st->time_2_die)
		{
			st->die = 1;
			pthread_mutex_lock(&(st->death));
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
