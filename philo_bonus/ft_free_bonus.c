/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:53:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/22 11:41:41 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_philo(t_philo *philo, int n, int flag)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	while (philo && i++ < n)
	{
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
}

// void	free_mutex(t_sem *mutex, int n)
// {
// 	int		i;
// 	t_sem	*tmp;

// 	i = 0;
// 	while (mutex && i++ < n)
// 	{ 
// 		tmp = mutex;
// 		mutex = mutex->next;
// 		free (tmp);
// 	}
// }

void	ft_free(t_data *st, int flag)
{
	if (!flag)
		return ;
	free_philo(st->s_philo, st->philo_n, flag);
}
