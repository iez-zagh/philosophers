/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/19 19:55:12 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_threads(t_philo *philo, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
	{
		pthread_join(philo->id, NULL);
		philo = philo->next;
	}
}

void	check_death(t_data *st, int n, t_philo *philo)
{
	wait_death(st);
	wait_threads(philo, n);
	ft_free(st, 1);
}

void	thread_failure(t_data *st, t_philo *philo)
{
	wait_threads(philo, st->philo_n);
	write(2, "tread error\n", 12);
	ft_free(st, 1);
}

int	create_threads(t_data *st)
{
	t_philo		*philo;
	int			i ;
	int			n;

	42 && (philo = st->s_philo, i = 0, n = st->philo_n);
	if (pthread_mutex_init(&(st->node_mutex), NULL)
		|| pthread_mutex_init(&(st->var_mutex), NULL)
		|| pthread_mutex_init(&st->death, NULL))
		return (ft_free(st, 1), 1);
	st->die = 0;
	st->time = get_time();
	while (i++ < n)
	{
		philo->last_meal = get_time();
		if (pthread_create(&(philo->id), NULL, routine, st))
			return (thread_failure(st, st->s_philo), 1);
		philo = philo->next;
	}
	check_death(st, n, philo);
	return (0);
}
