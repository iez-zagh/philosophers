/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:03:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/23 20:55:52 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print(t_data *st, t_philo *philo, char *msg)
{
	sem_wait(st->die);
	if (st->die_)
		return (sem_post(st->die), 1);
	printf("%lu %d %s\n", get_time() - st->time, philo->index, msg);
	sem_post(st->die);
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

t_philo	*get_node(t_philo *philo, t_data *st, int index)
{
	int			j;

	j = 0;
	while (j < index)
	{
		philo = philo->next;
		j++;
	}
	index++;
	return (philo);
}


// t_philo	*init_philo(t_data *st)
// {
// 	t_philo	*philo;

// 	philo = get_node(st->s_philo, st);
// 	if (philo && philo->index % 2 == 0)
// 		usleep(2000);
// 	return (philo);
// }

void	*check_death2(void *arg)
{
	t_data	*st;
	t_philo	*philo;

	st = (t_data *)arg;
	philo = get_node(st->s_philo, st, st->index);
	wait_death(st, philo);
	return (NULL);
}

void	*true_routine(t_data *st, t_philo *philo)// need to pass the adress of the time
{
	if (pthread_create(&philo->id, NULL, check_death2, st))
		return (write(2, "error\n", 6), NULL);
	int	i;
	i = 0;
	while (1)
	{
		// if (!i)
		// {
		// 	sem_post(philo->meals);
		// 	i++;
		// }
		sem_wait(st->forks);
		if (print(st, philo, FORK))
			exit (0);
		sem_wait(st->forks);
		if (st->philo_n == 1)
			exit (0);
		if (print(st, philo, FORK))
			exit (0);
		if (print(st, philo, EAT))
			exit (0);

		philo->last_meal = get_time();

		ft_usleep(st->time_2_eat);
		sem_post(st->forks);
		sem_post(st->forks);
		if (sleep_think(st, philo))
			exit (0);
	}
}

void	*routine(t_data *st, t_philo *philo)
{
	// if (philo && philo->index % 2 == 0)
	// 	usleep(2000);
	if (!true_routine(st, philo))
		return (NULL);
	return (NULL);
}
