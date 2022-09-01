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
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_utils
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_philo;
	int				nbr_of_times_each_philo_must_eat;
	int				is_died;
	pthread_mutex_t	*fork;
	pthread_mutex_t print;
	
}	t_utils;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	pthread_mutex_t			right_fork;
	pthread_mutex_t			*left_fork;
	
	t_utils		*utils;
	int			last_eat;
	int			nbr_of_eat;
	int 		argc;
}	t_philo;



//utils
int	ft_atoi(const char *str);
long long	ft_sleep(int time_in_milliseconds);
int	ft_isdigit(int c);
long long	gettime();
int ft_chaeck_args(char *str);
int ft_check_numbers(int argc, char **argv);
int ft_check_error(t_utils utils, int argc, char **argv);
void	*routine(void *philo);
void	*check_is_died(void *ph);
int	ft_num_eating_check(t_philo *philo, int n_eat, int argc);
void	ft_create_threads(t_utils *utils,t_philo *philo);
void	ft_create_philo(t_utils *utils,t_philo *philo, int ac);
void    ft_insert_args(t_utils *utils, int argc, char **argv);
void	ft_usleep(long long time, t_utils *utils);
void	ft_printf(char *str, t_utils *utils, int id);

#endif