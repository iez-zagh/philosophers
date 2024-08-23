/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/23 20:32:54 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


void	check_death(t_data *st, int n, t_philo *philo)
{
	int	i;

	i = 0;
	sem_wait(st->die_2);
	// sem_wait(st->die);
	while (i < n)
	{
		sem_close(philo->meals);
		kill(philo->pid, SIGKILL);
		i++;
		philo = philo->next;
	}
	sem_close(st->forks);
	sem_close(st->die);
	sem_close(st->die_2);
    sem_unlink("/sema2");
    sem_unlink("/kill");
    sem_unlink("/meals");
    sem_unlink("/print");
	// ft_free(st, 1);
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
	st->die_ = 0;
	st->index = 0;
	st->time = get_time();
	while (i++ < n)
	{
		philo->last_meal = get_time();
		philo->pid  = fork();
		if (!philo->pid)
			routine(st, philo);
		else
		{
			philo = philo->next;
			st->index++;
		}
	}
	check_death(st, n, philo);
	return (0);
}
