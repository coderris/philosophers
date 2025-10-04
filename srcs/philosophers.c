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
	ft_struct_init(&general, imputs);
	free(imputs);
	return (0);
}