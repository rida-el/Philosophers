/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:34:34 by rel-maza          #+#    #+#             */
/*   Updated: 2022/08/31 21:42:39 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int argc, char **argv)
{

    t_utils utils;
    t_philo *philo;
	int i;

	// printf("hello i am here\n");
    if (argc != 5 && argc != 6)
        return (printf("error\n") , 1);
    ft_insert_args(&utils, argc, argv);
    if (ft_check_error(utils, argc, argv) == 0)
        return (0);
    philo = malloc(sizeof(t_philo) * utils.nbr_of_philo);
    utils.fork = malloc(sizeof(pthread_mutex_t) * utils.nbr_of_philo);
	i = 0;
	while(i < utils.nbr_of_philo)
	{	
		pthread_mutex_init(&(utils.fork[i]),NULL);
		i++;
	}
	pthread_mutex_init(&utils.print,NULL);
    ft_create_philo(&utils, philo, argc);

	ft_create_threads(&utils, philo);
	while (1)
	{
		if((check_is_died(&philo)) == 0)
			return (0);
	}
	
	
}