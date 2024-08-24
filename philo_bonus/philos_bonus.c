/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:03:02 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/24 17:39:06 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

t_philo	*change_node(int i)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (write(2, "malloc error\n", 13), NULL);
	new->index = i + 1;
	new->next = NULL;
	new->meals_n = 0;
	sem_unlink("/meals_n");
	sem_unlink("/last_meal");
	new->last_meal_ = sem_open("/last_meal", O_CREAT, 0644, 1);
	new->meals_n_ = sem_open("/meals_n", O_CREAT, 0644, 1);
	if (new->last_meal_ == SEM_FAILED || new->meals_n_ == SEM_FAILED)
		return (NULL);
	return (new);
}

void	initialze_philo(t_data *st)
{
	t_philo	*philo;
	t_philo	*new;
	t_philo	*first;
	int		i;

	42 && (i = 0, philo = NULL);
	while (i < st->philo_n)
	{
		new = change_node(i);
		if (!new)
		{
			st->s_philo = NULL;
			return ;
		}
		if (!i)
			first = new;
		add_back2(&philo, new);
		i++;
	}
	if (new)
		new->next = first;
	st->s_philo = philo;
}

int	initializing_philos(t_data *st)
{
	st->forks = create_semaphore(st->philo_n);
	if (!st->forks)
		return (1);
	sem_unlink("/kill");
	sem_unlink("/print");
	sem_unlink("/start");
	st->die = sem_open("/print", O_CREAT, 0644, 1);
	st->start = sem_open("/start", O_CREAT, 0644, 1);
	st->die_2 = sem_open("/kill", O_CREAT, 0644, 1);
	st->die = SEM_FAILED;
	if (st->die == SEM_FAILED || st->start == SEM_FAILED || st->die_2 == SEM_FAILED)
		return (1);
	sem_wait(st->die_2);
	initialze_philo(st);
	if (!st->s_philo)
		return (ft_free(st, 0), 1);
	return (create_philos(st));
}
