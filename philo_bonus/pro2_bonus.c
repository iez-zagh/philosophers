/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:03:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/24 23:11:08 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print(t_data *st, t_philo *philo, char *msg)
{
	sem_wait(st->die);
	printf("%lu %d %s\n", get_time() - st->time, philo->index, msg);
	sem_post(st->die);
	return (0);
}

int	sleep_think(t_data *st, t_philo *philo)
{
	sem_wait(philo->meals_n_);
	philo->meals_n++;
	sem_post(philo->meals_n_);
	if (print(st, philo, SLEEP))
		return (1);
	ft_usleep(st->time_2_sleep);
	if (print(st, philo, THINK))
		return (1);
	return (0);
}

t_philo	*get_node(t_philo *philo, int index)
{
	int	j;

	j = 0;
	while (j < index)
	{
		philo = philo->next;
		j++;
	}
	index++;
	return (philo);
}

void	*check_death2(void *arg)
{
	t_data	*st;
	t_philo	*philo;

	st = (t_data *)arg;
	philo = get_node(st->s_philo, st->index);
	wait_death(st, philo);
	return (NULL);
}

void	*true_routine(t_data *st, t_philo *philo)
{
	philo->ppid = getppid();
	if (pthread_create(&philo->id, NULL, check_death2, st))
		return (write(2, "thread error\n", 13), NULL);
	while (1)
	{
		sem_wait(st->forks);
		if (print(st, philo, FORK))
			exit (0);
		sem_wait(st->forks);
		if (print(st, philo, FORK))
			exit (0);
		if (print(st, philo, EAT))
			exit (0);
		sem_wait(philo->last_meal_);
		philo->last_meal = get_time();
		sem_post(philo->last_meal_);
		ft_usleep(st->time_2_eat);
		sem_post(st->forks);
		sem_post(st->forks);
		if (sleep_think(st, philo))
			exit (0);
	}
}
