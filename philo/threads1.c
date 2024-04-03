/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:06:59 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/03 03:32:50 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int x = 2;

void	threads1(void)
{
	pthread_t	t1, t2;

	pthread_create(&t1, NULL, &philo_life, NULL);
	pthread_create(&t2, NULL, &philo_life2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}

void	*philo_life()
{
	printf("%d\n", getpid());
	printf("%p\n", &x);
	x++;
	sleep (2);
	printf("%d\n", x);
	return (NULL);
}

void	*philo_life2()
{
	printf("%d\n", getpid());
	printf("%p\n", &x);
	sleep(1);
	printf("%d\n", x);
	return (NULL);
}

void	initalize_threads(t_data *st)
{
	threads1();
	st++;
}