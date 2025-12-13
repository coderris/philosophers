/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:48:03 by lanton-m          #+#    #+#             */
/*   Updated: 2025/12/02 12:48:03 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	clean_all(t_general_info *general, long long *imputs)
{
	int	i;

	i = 0;
	if (imputs)
		free(imputs);
	if (!general)
		return ;
	while (i < general->philo_num)
		pthread_mutex_destroy(&general->forks[i++]);
	pthread_mutex_destroy(&general->print_lock);
	pthread_mutex_destroy(&general->state_lock);
	free(general->forks);
	free(general->philos);

}