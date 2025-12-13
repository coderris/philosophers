/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:40:39 by lanton-m          #+#    #+#             */
/*   Updated: 2025/10/03 23:40:39 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	set_last_meal(t_general_info *general)
{
	int	i;

	i = 0;
	while (i < general->philo_num)
		general->philos[i++].last_meal = general->start_time;
}

int	main(int argc, char** argv)
{
	t_general_info		general;
	long long			*imputs;
	pthread_t			monitor_thread;
	int					i;

	i = 0;
	parser(argc, argv);
	imputs = ft_handle_input(argc, argv);
	ft_structs_init(&general, imputs);
	general.start_time = ft_get_time();
	set_last_meal(&general);
	ft_philo_threads_init(&general);
	pthread_create(&monitor_thread, NULL, monitor_routine, &general);
	while (i < general.philo_num)
		pthread_join(general.philos[i++].thread, NULL);
	pthread_join(monitor_thread, NULL);
	clean_all(&general, imputs);
	return (0);
}
