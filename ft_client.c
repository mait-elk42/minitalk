/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:09:44 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/01 21:29:49 by mait-elk         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3 || _nsx_atoi(argv[1]) <= 0)
	{
		_nsx_pcolor('r');
		_nsx_ps("ERROR : INVALID (PID OR SYNTAX)");
		_nsx_pcolor(0);
		return (-1);
	}
	pid = _nsx_atoi(argv[1]);
	_nsx_send_str(argv[2], pid);
	_nsx_send_char('\0', pid);
	return (0);
}
