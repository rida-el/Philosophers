/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:06:22 by rel-maza          #+#    #+#             */
/*   Updated: 2022/08/28 17:22:09 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_utils
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_philo;
	int				nbr_of_times_each_philo_must_eat;
	pthread_mutex_t	*fork;
}	t_utils;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	int			right_fork;
	int			left_fork;
	int			is_died;
	
}	t_philo;



//utils
int	ft_atoi(const char *str);


#endif