/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nemethnikol <nemethnikol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:27 by nemethnikol       #+#    #+#             */
/*   Updated: 2022/08/22 12:57:25 by nemethnikol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophate(t_table *tab)
{
	int	i;

	i = -1;
	while (++i < tab->n_philos)
	{
		if (pthread_create(&tab->philos[i].th, NULL, &philo_life,
			&tab->philos[i]));
	}
	i = -1;
	while (++i < tab->n_philos)
	(
		if (pthread_join(&tab->philos[i].th, NULL) != 0)
			return (error);
	)
	return (0);
}