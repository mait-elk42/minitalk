/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:09:44 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/07 13:09:51 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	_nsx_send_char(char c, int pid)
{
	int		i;

	i = 8;
	while (i--)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR1) == -1)
				_nsx_ps_exit("INVALID PID", -1, 'r');
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				_nsx_ps_exit("INVALID PID", -1, 'r');
		}
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

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = _nsx_atoi(argv[1]);
	if (argc != 3)
		_nsx_ps_exit("ERROR : INVALID SYNTAX", -1, 'r');
	if (pid <= 0)
		_nsx_ps_exit("ERROR : INVALID PID", -1, 'r');
	if (argv[2][0] == '\0')
		_nsx_ps_exit("ERROR : YOU CAN'T SEND EMPTY MESSAGE", -1, 'r');
	_nsx_send_str(argv[2], pid);
	return (0);
}
