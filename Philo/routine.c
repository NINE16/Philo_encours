/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:13:18 by nemethnikol       #+#    #+#             */
/*   Updated: 2022/09/09 18:56:52 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_life(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = data;
	table = philo->table;
	if (philo->id % 2 != 0)
		ft_usleep(table->time_to_eat, philo);
	while (table->dead == 0 )
	{
		if (take_fork(philo, table))
			break ;
		if (table->dead == 0)
			sleeping(philo, table);
			// break ;
		// if (table->dead == 0)
			// write_status("is thinking 🧐", philo);

	}
	return (NULL);
}

int	take_fork(t_philo *philo, t_table *table)
{	
	int i;

	i = 0;
	pthread_mutex_lock(&philo[philo->id].fork);
	philo->start_time = table->philos->start_time;
	// if (table->dead == 0)
	write_status("Has taken the right fork 🥢", philo);
	pthread_mutex_lock(&philo[(philo->id - 1)].fork);
	write_status("Has taken the left fork 🥢", philo);
	write_status("Is eating 🍔", philo);
	if (table->quant_food != -1)
		philo->n_meals++;
	philo->last_meal = ft_set_time(philo);
	ft_usleep(table->time_to_eat, philo);
	// pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_unlock(&philo[philo->id].fork);
	pthread_mutex_unlock(&philo[(philo->id - 1)].fork);
	return (0);
}

void	sleeping(t_philo *philo, t_table *table)
{
	// if (table->dead == 0)
	write_status("is sleeping 🧐", philo);
	// pthread_mutex_unlock(&table->write);
	ft_usleep(table->time_to_sleep, philo);
	// pthread_mutex_lock(&table->write);
	// if (table->dead == 0)
	write_status("is thinking 🧐", philo);
	// pthread_mutex_unlock(&table->write);

}

void	write_status(char *str, t_philo *philo)
{
	long int	time;

	time = ft_set_time(philo);
	pthread_mutex_lock(&philo->table->write);
	printf("%ld ", time);
	printf("Philo %d %s\n", philo->id, str);
	pthread_mutex_unlock(&philo->table->write);
}
