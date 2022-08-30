/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nemethnikol <nemethnikol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:06:15 by nemethnikol       #+#    #+#             */
/*   Updated: 2022/08/22 11:51:32 by nemethnikol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define MAX_INT 2147483647

typedef struct s_table t_table;

typedef struct s_philo
{
	t_table	*table;
	int		next;
	int		last_meal;
	int		wait;
	int 	meals;
	int		id;
	pthread_t	th;
	pthread_mutex_t	fork;
}	t_philo;

typedef struct s_table
{
	t_philo	*philos;
	int	n_philos;
	int time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	int	quant_food;
	int	death;
}	t_table;


int	ft_atoi_check(char *str);
int	ft_isdigit(int c);
int	get_args(int argc, char **argv, t_table *table);


#endif