/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:06:22 by rel-maza          #+#    #+#             */
/*   Updated: 2022/08/25 00:06:24 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_utils
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_philo;
	int				nbr_of_times_each_philo_must_eat;
	pthread_mutex_h	fork;
}	t_utils;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	
}	t_philo;



//utils
int	ft_atoi(const char *str);


#endif