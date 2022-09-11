/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:06:22 by rel-maza          #+#    #+#             */
/*   Updated: 2022/09/01 23:12:12 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_utils
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_philo;
	int				times_must_eat;
	int				is_died;
	pthread_mutex_t	death;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	long long		timestamp_in_ms;
	long long		first_time;

}	t_utils;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	int			right_fork;
	int			left_fork;
	t_utils		*utils;
	long long	last_eat;
	int			nbr_of_eat;
	int			argc;
}	t_philo;

// utils
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
long long	gettime(void);
int			ft_chaeck_args(char *str);
int			ft_check_numbers(int argc, char **argv);
int			ft_check_error(t_utils utils, int argc, char **argv);
void		*routine(void *philo);
void		ft_usleep(int time_to_sleep);
int			check_is_died(t_utils *utils, t_philo *philo, int argc);
int			ft_num_eating_check(t_philo *philo,
				int n_eat, int nbr_of_philo, int argc);
void		ft_create_threads(t_utils *utils, t_philo *philo);
void		ft_create_philo(t_utils *utils, t_philo **ph, int ac);
void		ft_insert_args(t_utils *utils, int argc, char **argv);
void		ft_printf(char *str, t_utils *utils, t_philo *philo);

#endif