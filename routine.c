/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:13:18 by nemethnikol       #+#    #+#             */
/*   Updated: 2022/09/19 17:31:29 by nnemeth          ###   ########.fr       */
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
		ft_usleep(table->time_to_eat, philo, table);
	while (table->dead == 0)
	{
		if (take_fork(philo, table))
			break ;
		if (table->dead == 0)
			(start_eat(philo, table));
		if (table->dead == 0)
			sleeping(philo, table);
		if (table->dead == 0)
			write_status(PURPLE "is thinking 🧐", philo);
	}
	return (NULL);
}

int	take_fork(t_philo *philo, t_table *table)
{	
	int	i;

	i = 0;
	philo->start_time = table->philos->start_time;
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->table->philos[philo->next].fork);
	if (table->dead == 0)
	{
		write_status(GREEN "Has taken the right fork 🥢" , philo);
		write_status(GREEN "Has taken the left fork 🥢", philo);
	}
	return (0);
}

int	start_eat(t_philo *philo, t_table *table)
{
	write_status(YELLOW "Is eating 🍔", philo);
	philo->last_meal = ft_set_time(philo);
	if (table->quant_food != -1)
		philo->n_meals++;
	ft_usleep(table->time_to_eat, philo, table);
	drop_forks(philo);
	return (0);
}

int drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->table->philos[philo->next].fork);
	return (0);
}

void	sleeping(t_philo *philo, t_table *table)
{
	write_status(RED "is sleeping 🧐", philo);
	ft_usleep(table->time_to_sleep, philo, table);
}

void	write_status(char *str, t_philo *philo)
{
	long int	time;

	time = ft_set_time(philo);
	pthread_mutex_lock(&philo->table->write);
	printf(WHITE "%s%ld ", "Time:", time);
	printf(WHITE "  Philo %d    %s\n", philo->id, str);
	pthread_mutex_unlock(&philo->table->write);
}
