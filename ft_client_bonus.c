/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:09:44 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/08 18:03:56 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	_nsx_send_char(char c, int pid)
{
	int		i;

	i = 8;
	while (i--)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		}
		usleep(100);
		c <<= 1;
	}
	return (0);
}

int	_nsx_send_str(char *str, int pid)
{
	while (*str)
	{
		if (_nsx_send_char(*str, pid) == -1)
			return (-1);
		str++;
	}
	_nsx_send_char('\0', pid);
	return (0);
}

void	_nsx_handler(int sig)
{
	if (sig == SIGUSR1)
		_nsx_ps_exit("MESSAGE RECEIVED :)", 0, 'g');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = _nsx_atoi(argv[1]);
	handle_errors(argc, argv, pid);
	signal(SIGUSR1, _nsx_handler);
	if (_nsx_send_str(argv[2], pid) == -1)
		_nsx_ps_exit("MESSAGE FAILED :(", 0, 'r');
	return (0);
}
