/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/22 10:25:50 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


void	check_death(t_data *st, int n, t_philo *philo)
{
	// ()
	wait_death(st);
	ft_free(st, 1);
}

void	thread_failure(t_data *st, t_philo *philo)
{
	// wait process
	write(2, "tread error\n", 12);
	ft_free(st, 1);
}

int	create_threads(t_data *st)
{
	t_philo		*philo;
	int			i ;
	int			n;

	42 && (philo = st->s_philo, i = 0, n = st->philo_n);
	st->die = 0;
	st->time = get_time();
	while (i++ < n)
	{
		philo->last_meal = get_time();
		// here fork;
		philo->pid  = fork();
		if (!philo->pid)
		{
			routine(st);
		}
		philo = philo->next;
	}
	check_death(st, n, philo);
	return (0);
}
