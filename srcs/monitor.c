/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:01:55 by lanton-m          #+#    #+#             */
/*   Updated: 2025/11/29 22:01:55 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	monitor_routine(t_general_info *general)
{
	int i;
	long long current_time;
	long long no_eat_time;
	
	i = 0;
	while (1)
	{
		while(i < general->philo_num)
		{
			pthread_mutex_lock(&general->state_lock);
			current_time = ft_current_time(general.start_time);
			no_eat_time = current_time - general->philos[i].last_meal;
			if (no_eat_time > general.tte)
			{
				general.stop = 1;
				ft_print_status(general->philos[i], "died");
				pthread_mutex_unlock(&general->state_lock);
				return (1);
			}
			pthread_mutex_unlock(&general->state_lock);
			i++;
		}
		if (general->must_eat != -1)
		{
				if ()
		}
	}
}