/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:15 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/04 08:14:21 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		exit (0);
	if (ac < 5 || ac > 6)
	{
		write (2, "wrong number of arguments !!\n", 29);
		exit (1);
	}
	parser(ac, av);
	return (0);
}

void	error(t_data *st, int y)
{
	if (y == 1)
		write (2, "malloc faillure!\n", 17);
	if (y == 2)
		write (2, "there is some thing wrong in the given arguments!\n", 50);
	if (y == 4)
		write (2, "error in gettimeofday function!\n", 32);
	if (y == 3)
		write (2,
			"big number, it's gona take so much time, try some thing smaller\n",
			64);
	if (!st)
		free (st);
	exit (1);
}
