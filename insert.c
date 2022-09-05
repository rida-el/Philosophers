/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:24:58 by rel-maza          #+#    #+#             */
/*   Updated: 2022/08/31 19:49:41 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void    ft_insert_args(t_utils *utils, int argc, char **argv)
{

    utils->nbr_of_philo = ft_atoi(argv[1]);
    utils->time_to_die = ft_atoi(argv[2]);
    utils->time_to_eat = ft_atoi(argv[3]);
    utils->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
    {
        utils->nbr_of_times_each_philo_must_eat = ft_atoi(argv[5]);
    }
    utils->is_died = 0;
}