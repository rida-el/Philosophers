#ifndef PHILO_H
# define PHILO_H


typedef struct s_utils
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;
}	t_utils;


#endif