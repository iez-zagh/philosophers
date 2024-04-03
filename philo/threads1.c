/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:06:59 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/03 07:41:26 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads1(t_data *st)
{
	int	i;

	i = 0;
	while (i < st->philo_n)
	{
		create_thread(st);
		i++;
	}

// 	pthread_t	t1, t2;

// 	pthread_create(&t1, NULL, &philo_life, NULL);
// 	pthread_create(&t2, NULL, &philo_life2, NULL);
// 	pthread_join(t1, NULL);
// 	pthread_join(t2, NULL);
}

// void	*philo_life()
// {

// }

// void	*philo_life2()
// {

// }
void	create_thread(t_data *st)
{

}