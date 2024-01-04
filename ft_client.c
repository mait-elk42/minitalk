/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:09:44 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/04 12:42:16 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			if (kill(pid, SIGUSR2))
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
	_nsx_send_char('\n', pid);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3 || _nsx_atoi(argv[1]) < 0)
	{
		_nsx_pcolor('r');
		_nsx_ps("ERROR : INVALID (PID OR SYNTAX)");
		_nsx_pcolor(0);
		return (-1);
	}
	pid = _nsx_atoi(argv[1]);
	if (_nsx_send_str(argv[2], pid) == -1)
	{
		_nsx_pcolor('r');
		_nsx_ps("INVALID SERVER PID");
		_nsx_pcolor(0);
		return (-1);
	}
	return (0);
}
