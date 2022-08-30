/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nemethnikol <nemethnikol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:13:18 by nemethnikol       #+#    #+#             */
/*   Updated: 2022/08/22 14:07:42 by nemethnikol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*philo_life(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;

	while(philo->table->death == 0)
	{
		if (take_fork(philo))
			break ;
		if (start_eating(philo))
			break ;
		philo_sleep(philo);
		print_status(philo, "is thinking");	
	}
}

void	*routine(void *data)
{
	t_philo *philo;


}
