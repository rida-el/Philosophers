/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:12:31 by rel-maza          #+#    #+#             */
/*   Updated: 2022/08/30 14:22:02 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_check_args(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int ft_check_numbers(int argc, char **argv)
{
    if (!ft_check_args(argv[1]) || !ft_check_args(argv[2]) || !ft_check_args(argv[3]) || !ft_check_args(argv[4]))
        return (printf("error"), 0);
    if (argc == 6)
        if (!ft_check_args(argv[5]))
            return (printf("error"), 0);
    return (1);
}

int ft_check_error(t_utils utils, int argc, char **argv)
{
    if (!ft_check_numbers(argc, argv))
        return (printf("error\n"), 0);
    if (argc == 6 && utils.nbr_of_times_each_philo_must_eat <= 0)
        return (printf("error\n"), 0);
    if (utils.nbr_of_philo < 1)
        return (printf("error num fo philo\n"), 0);
    if (utils.time_to_die < 60)
        return (printf("error time to die\n"), 0);
    if (utils.time_to_eat < 60)
        return (printf("error time to eat\n"), 0);
    if (utils.time_to_sleep < 60)
        return (printf("error time to sleep\n"), 0);
    return (1);
}