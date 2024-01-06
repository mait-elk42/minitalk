/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:09:44 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/06 19:41:05 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_msg_status;

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
	if (sig == SIGUSR2)
		g_msg_status = 0;
	if (sig == SIGUSR1)
		g_msg_status = 1;
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	g_msg_status = 0;
	if (argc == 3 && _nsx_atoi(argv[1]) > 0)
	{
		pid = _nsx_atoi(argv[1]);
		signal(SIGUSR1, _nsx_handler);
		signal(SIGUSR2, _nsx_handler);
		if (_nsx_send_str(argv[2], pid) != -1 && g_msg_status)
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
	_nsx_pcolor('r');
	return (_nsx_ps("ERROR : INVALID (PID OR SYNTAX)"), -1);
}
