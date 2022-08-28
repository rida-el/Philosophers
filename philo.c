/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:34:34 by rel-maza          #+#    #+#             */
/*   Updated: 2022/08/25 00:36:55 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{

    t_utils utils;
    t_philo *philo;

    if (argc != 5 && argc != 6)
    {
        write(1, "error\n", 6);
        return (0);
    }
    ft_insert_args(utils, argc, argv);
    if (!ft_check_error(utils, argv, argc))
        return (0);
    philo = malloc(sizeof(t_philo) * utils.nbr_of_philo);
    utils.fork
    
}