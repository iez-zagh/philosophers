
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:06:59 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/18 23:27:47 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(useconds_t time)
{	
	size_t	start;
	start = get_time();
	while ((get_time() - start) < time) //check the time if its completed
		usleep(time / 10); //remember this later
	return(0);
}

size_t	get_time(void)
{
	struct timeval	the_time;

	gettimeofday(&the_time, NULL);
	return ((the_time.tv_sec * 1000) + (the_time.tv_usec / 1000));
}
