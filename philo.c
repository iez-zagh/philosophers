/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:15 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/10 09:45:32 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int 	parser(int ac, char **av)
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
	// printf("%d]]\n", st.philo_n);
	// printf("%d]]\n", st.time_2_die);
	// printf("%d]]\n", st.time_2_eat);
	// printf("%d]]\n", st.time_2_sleep);
	// if (st->philo_n > 200 || st->time_2_die > 1000000
	// 	|| st->time_2_eat > 1000000 || st->time_2_sleep > 1000000)
	// {
	// 	return (1);
	// }
	threads1(&st);
	return (0);
}

int	main(int ac, char **av)
{
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
