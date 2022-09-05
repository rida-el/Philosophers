/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:34:34 by rel-maza          #+#    #+#             */
/*   Updated: 2022/09/01 23:36:17 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{

	t_utils utils;
	t_philo *philo;
	// pthread_t watcher;
	int i;

	// printf("hello i am here\n");
	if (argc != 5 && argc != 6)
		return (printf("error\n"), 1);
	ft_insert_args(&utils, argc, argv);
	if (ft_check_error(utils, argc, argv) == 0)
		return (0);
	philo = malloc(sizeof(t_philo) * utils.nbr_of_philo);
	utils.fork = malloc(sizeof(pthread_mutex_t) * utils.nbr_of_philo);
	i = 0;
	while (i < utils.nbr_of_philo)
	{
		pthread_mutex_init(&(utils.fork[i]), NULL);
		// pthread_mutex_init(&(philo[i].access),NULL);
		i++;
	}
	pthread_mutex_init(&utils.print, NULL);
	// pthread_mutex_init(&utils.death,NULL);
	// pthread_mutex_lock(&utils.death);
	ft_create_philo(&utils, &philo, argc);

	// pause();
	ft_create_threads(&utils, philo);
	// check_is_died(&philo);
	if (check_is_died(&utils, philo, argc))
		return (0);
	// pthread_mutex_lock(&utils.death);
	// i = 0;
	// while (i < utils.nbr_of_philo) {
	// 	pthread_mutex_lock(&(philo[i].access));
	// 	pthread_detach(philo[i].thread);
	// 	i++;
	// }
	// pause();
	// pthread_join(watcher, NULL);

	// if(check_is_died(philo)== 0)
	// 	return (0);
}