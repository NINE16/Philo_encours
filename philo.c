/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:27 by nemethnikol       #+#    #+#             */
/*   Updated: 2022/09/23 17:47:13 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophate(t_table *table)
{
	int	i;

	i = -1;
	if (table->n_philos == 1)
		one_philo(table->philos);
	while (++i < table->n_philos)
	{
		if (pthread_create(&table->philos[i].th, NULL, &philo_life,
				&table->philos[i]))
			return (-1);
	}
	pthread_create(&table->death, NULL, &dead_yet, &table);
	i = -1;
	while (++i < table->n_philos)
	{
		if (pthread_join(table->philos[i].th, NULL) != 0)
			return (0);
	}
	pthread_join(table->death, NULL);
	pthread_mutex_destroy(&table->mutex_dead);
	pthread_mutex_destroy(&table->write);
	return (0);
}

void	one_philo(t_philo *philo)
{
	long int	time;

	time = ft_set_time(philo);
	pthread_mutex_lock(&philo->fork);
	write_status(GREEN "Has taken the left fork 🥢", philo);
	pthread_mutex_unlock(&philo->fork);
	while (1)
	{
		if (ft_set_time(philo) - time >= philo->table->time_to_die)
		{
			philo->table->dead++;
			write_status("Is dead", philo);
			return ;
		}
	}
}
