/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:15 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/20 09:31:23 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	parser(int ac, char **av)
{
	t_data	st;

	if (checker(ac, av))
	{
		write (2, "some thing wrong in the args\n", 29);
		how_to_use();
		return (1);
	}
	st.philo_n = my_atoi(av[1]);
	st.time_2_die = my_atoi(av[2]);
	st.time_2_eat = my_atoi(av[3]);
	st.time_2_sleep = my_atoi(av[4]);
	if (ac == 6)
		st.eat_n = my_atoi(av[5]);
	else
		st.eat_n = -1;
	if (st.eat_n == 0)
		return (0);
	if (st.time_2_die == -1
		|| st.time_2_eat == -1 || st.time_2_sleep == -1)
		return (write(2, "some thing wrong in the args\n", 29)
			, how_to_use(), 1);
	return (initializing_threads(&st));
}

void	f(void)
{
	system("leaks philo");
}

int	main(int ac, char **av)
{
	// atexit (f);
	if (ac < 5 || ac > 6)
	{
		write(2, "invalid number of args\n", 23);
		how_to_use();
		return (1);
	}
	if (parser(ac, av))
		return (1);
	return (0);
}

int	check_meals(t_philo *philo, t_data *st)
{
	int	i;

	i = 0;
	while (i++ < st->philo_n)
	{
		pthread_mutex_lock(&(philo->meals_n_mutex));
		if (philo->meals_n < st->eat_n)
			return (pthread_mutex_unlock(&(philo->meals_n_mutex)), 1);
		pthread_mutex_unlock(&(philo->meals_n_mutex));
		philo = philo->next;
	}
	pthread_mutex_lock(&(st->death));
	st->die = 1;
	pthread_mutex_unlock(&(st->death));
	return (0);
}

void	wait_death(t_data *st)
{
	t_philo	*philo;

	philo = st->s_philo;
	while (philo)
	{
		if (st->eat_n != -1
			&& !check_meals(st->s_philo, st))
			return ;
		pthread_mutex_lock(&(philo->last_meal_mutex));
		if (get_time() - philo->last_meal > (size_t)st->time_2_die)
		{
			pthread_mutex_unlock(&(philo->last_meal_mutex));
			pthread_mutex_lock(&st->death);
			st->die = 1;
			pthread_mutex_unlock(&st->death);
			printf("%lu  %d   died\n", get_time() - st->time, philo->index);
			return ;
		}
		pthread_mutex_unlock(&(philo->last_meal_mutex));
		philo = philo->next;
	}
}
