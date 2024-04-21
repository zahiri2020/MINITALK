/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:48:42 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/21 13:20:35 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(char c, int id)
{
	int		bit;
	int		i;

	i = 0;
	bit = 128;
	while (i < 8)
	{
		if (c & bit)
		{
			if (kill(id, SIGUSR1) == -1)
				error_msg ("kill : No such process");
		}
		else
		{
			if (kill(id, SIGUSR2) == -1)
				error_msg ("kill: No such process");
		}
		c <<= 1;
		i++;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	id;

	i = 0;
	if (ac != 3)
		error_msg ("arguments not fount");
	id = ft_atoi(av[1]);
	if (id < 0)
	{
		ft_putstr("kill: illegal pid : ", 2);
		error_msg(av[2]);
	}
	while (av[2][i])
	{
		send_message (av[2][i], id);
		i++;
	}
}