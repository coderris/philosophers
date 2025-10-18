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

int	main(int argc, char** argv)
{
	t_general_info		general;
	long long			*imputs;

	parser(argc, argv);
	imputs = ft_handle_input(argc, argv);
	ft_structs_init(&general, imputs);
	general.start_time = ft_get_time();
	ft_philo_threads_init(&general);
	free(imputs);
	return (0);
}
