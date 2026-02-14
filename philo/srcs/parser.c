/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:45:12 by lanton-m          #+#    #+#             */
/*   Updated: 2026/02/14 20:45:12 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static long long	ft_atoi(char *str)
{
	long long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_check_nums(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (1);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	parser(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments.\n");
		printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat");
		printf(" time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		exit(1);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_check_nums(argv[i]))
		{
			printf("Invalid argument: %s\n", argv[i]);
			printf("Check your numbers please\n");
			exit(1);
		}
		i++;
	}
	return (0);
}

long long	*ft_handle_input(int rules, char **argv)
{
	int			i;
	long long	*nums;

	i = 1;
	nums = malloc(sizeof(long long) * rules);
	while (argv[i])
	{
		nums[i - 1] = ft_atoi(argv[i]);
		if (nums[i - 1] <= 0)
		{
			free(nums);
			printf("Invalid argument: %s\nCheck your numbers pls\n", argv[i]);
			exit(1);
		}
		i++;
	}
	return (nums);
}
