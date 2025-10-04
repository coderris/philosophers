/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:39:12 by lanton-m          #+#    #+#             */
/*   Updated: 2025/10/03 23:39:12 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_general_info
{
	int				philo_num;
	long long		ttd;
	long long		tte;
	long long		tts;
	int				must_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	state_lock;
	int				stop;
	int				satisfied;
}	t_general_info;


int				parser(int argc, char **argv);
long long		*ft_handle_input(int rules, char **argv);
void			ft_struct_init(t_general_info *general, long long *imputs);

#endif