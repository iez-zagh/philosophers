/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:06:59 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/22 12:18:47 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_usleep(useconds_t time)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(100);
	return (0);
}

size_t	get_time(void)
{
	struct timeval	the_time;

	gettimeofday(&the_time, NULL);
	return ((the_time.tv_sec * 1000) + (the_time.tv_usec / 1000));
}

// t_sem	*get_last(t_sem *philo)
// {
// 	if (!philo)
// 		return (NULL);
// 	while (philo->next)
// 		philo = philo->next;
// 	return (philo);
// }

// void	add_back(t_sem **philo, t_sem *new)
// {
// 	if (!*philo)
// 		*philo = new;
// 	else
// 	{
// 		get_last(*philo)->next = new;
// 		new->next = NULL;
// 	}
// }

sem_t	*create_semaphore(int i)
{
	int		j;
	sem_t	*sem1;

	j = 0;
	sem1[j] = sem_open("/sema", O_CREAT , 0644, i);//the pe
	return (sem1);
}
