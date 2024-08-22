/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:03:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/22 15:23:12 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print(t_data *st, t_philo *philo, char *msg)
{
	if (st->die)
		return (1);
	printf("%lu %d %s\n", get_time() - st->time, philo->index, msg);
	return (0);
}

int	sleep_think(t_data *st, t_philo *philo)
{
	
	philo->meals_n++;
	
	if (print(st, philo, SLEEP))
		return (1);
	ft_usleep(st->time_2_sleep);
	if (print(st, philo, THINK))
		return (1);
	return (0);
}

t_philo	*get_node(t_philo *philo, t_data *st)
{
	int			j;
	static 	int i = 0;

	j = 0;
	while (j < st->index)
	{
		philo = philo->next;
		j++;
	}
	st->index++;
	return (philo);
}


t_philo	*init_philo(t_data *st)
{
	t_philo	*philo;

	philo = get_node(st->s_philo, st);
	if (philo && philo->index % 2 == 0)
		usleep(2000);
	return (philo);
}

void	*true_routine(t_data *st, t_philo *philo)// need to pass the adress of the time
{
	while (1)
	{
		sem_wait(st->forks);
		if (print(st, philo, FORK))
			return (NULL);
		sem_wait(st->forks);
		if (st->philo_n == 1)
			return (NULL);
		if (print(st, philo, FORK))
			return (NULL);
		if (print(st, philo, EAT))
			return (NULL);

		philo->last_meal = get_time();

		ft_usleep(st->time_2_eat);
		sem_post(st->forks);
		sem_post(st->forks);
		if (sleep_think(st, philo))
			return (NULL);
	}
}

void	*routine(t_data *st, t_philo *philo)
{
	if (philo && philo->index % 2 == 0)
		usleep(2000);
	pthread_create(&philo->id, NULL, check_death2(), st);
	if (!true_routine(st, philo))
		return (NULL);
	return (NULL);
}

void	*check_death(void *st)
{
	t_data	*st;

	st = (t_data *)st;
	
	
}