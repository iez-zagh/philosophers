/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:15 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/02 17:59:22 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	printf ("hi");
	if (ac == 1)
		exit (0);
	if (ac > 5)
		exit (1);
	parser(ac, av);
	return (0);
}

void	error(t_data *st, int y)
{
	if (y == 1)
		write (2, "malloc failure !", 16 );
	if (y == 2)
		write (2, "there is some thing wrong in arguments!", 40);
	free (st);
	exit (1);
}