/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:09:44 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/21 22:06:35 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_msg_status;

void	_nsx_send_char(char c, int pid)
{
	int		i;

	i = 8;
	while (i--)
	{
		if (c & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		c <<= 1;
	}
}

void	_nsx_send_str(char *str, int pid)
{
	while (*str)
	{
		_nsx_send_char(*str, pid);
		str++;
	}
}

void	_nsx_handler(int sig)
{
	if (sig == SIGUSR1)
		g_msg_status = 1;
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		_nsx_pcolor('r');
		_nsx_ps("INVALID SYNTAX :\nWRITE : ./client PID MESSAGE");
		_nsx_pcolor(0);
		return (-1);
	}
	pid = _nsx_atoi(argv[1]);
	signal(SIGUSR1, _nsx_handler);
	_nsx_send_str(argv[2], pid);
	_nsx_send_char('\0', pid);
	if (g_msg_status)
	{
		_nsx_pcolor('g');
		_nsx_ps("MESSAGE RECEIVED");
	}
	else
	{
		_nsx_pcolor('r');
		_nsx_ps("MESSAGE FAILED");
	}
	_nsx_pcolor(0);
	return (0);
}
