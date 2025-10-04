/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:48:07 by lanton-m          #+#    #+#             */
/*   Updated: 2025/10/04 00:48:07 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_struct_init(t_general_info *general, long long *imputs)
{
	int	i;

	general->philo_num = (int)imputs[0];
	general->ttd = imputs[1];
	general->tte = imputs[2];
	general->tts = imputs[3];
	if (imputs[4])
		general->must_eat = (int)imputs[4];
	else
		general->must_eat = -1;
	general->start_time = 0;
	general->forks = malloc(sizeof(pthread_mutex_t) * general->philo_num);
	if (!general->forks)
	{
		printf("Malloc error\n");
		free(imputs);
		exit(1);
	}
	i = 0;
	while (i < general->philo_num)
	{
		pthread_mutex_init(&general->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&general->print_lock, NULL);
	pthread_mutex_init(&general->state_lock, NULL);
	general->stop = 0;
	general->satisfied = 0;
}