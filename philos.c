/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:03:02 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/19 19:52:34 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*get_last2(t_philo *philo)
{
	if (!philo)
		return (NULL);
	while (philo->next)
		philo = philo->next;
	return (philo);
}

void	add_back2(t_philo **philo, t_philo *new)
{
	if (!*philo)
		*philo = new;
	else
	{
		get_last2(*philo)->next = new;
		new->next = NULL;
	}
}

t_philo	*change_node(t_mutex *mutex, int i)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->index = i + 1;
	pthread_mutex_init(&(new->last_meal_mutex), NULL);
	pthread_mutex_init(&(new->meals_n_mutex), NULL);
	new->r_fork = &(mutex->mutex);
	new->l_fork = &(mutex->next->mutex);
	new->meals_n = 0;
	new->next = NULL;
	return (new);
}

void	initialze_philo(t_data *st)
{
	t_philo	*philo;
	t_philo	*new;
	t_philo	*first;
	t_mutex	*mutex;
	int		i;

	42 && (i = 0, philo = NULL, mutex = st->mutexs);
	while (i < st->philo_n)
	{
		new = change_node(mutex, i);
		if (!new)
		{
			write(2, "malloc error\n", 13);
			st->s_philo = NULL;
			return ;
		}
		if (!i)
			first = new;
		add_back2(&philo, new);
		mutex = mutex->next;
		i++;
	}
	if (new)
		new->next = first;
	st->s_philo = philo;
}

int	initializing_threads(t_data *st)
{
	st->mutexs = create_mutex(st->philo_n);
	if (!st->mutexs)
		return (1);
	initialze_philo(st);
	if (!st->s_philo)
		return (ft_free(st, 0), 1);
	return (create_threads(st));
}
