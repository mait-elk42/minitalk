/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:41:13 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/08 18:03:26 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	_nsx_atoi(char *str)
{
	int	res;
	int	sig;

	sig = 1;
	res = 0;
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res *= 10;
		res += *str - 48;
		str++;
	}
	return (sig * res);
}

void	_nsx_putbanner(int pid, char *type)
{
	_nsx_ps("\033[1J\033[1;1H");
	_nsx_ps("\n");
	_nsx_pcolor('b');
	_nsx_ps("███╗░░░███╗██╗███╗░░██╗██╗ ████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
	_nsx_ps("████╗░████║██║████╗░██║██║ ╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
	_nsx_ps("██╔████╔██║██║██╔██╗██║██║ ░░░██║░░░███████║██║░░░░░█████═╝░\n");
	_nsx_ps("██║╚██╔╝██║██║██║╚████║██║ ░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
	_nsx_ps("██║░╚═╝░██║██║██║░╚███║██║ ░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
	_nsx_ps("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝ ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n");
	_nsx_ps(type);
	_nsx_ps("					\033[1;34m@mait-elk\n");
	_nsx_ps("\n\nPID:	\033[1;33m[ ");
	_nsx_pd(pid);
	_nsx_ps(" ]\n\033[1;34m");
	_nsx_ps("____________________________________________________________\n");
	_nsx_ps("\033[0m\n");
}

void	handle_errors(int argc, char **argv, int pid)
{
	if (argc != 3)
		_nsx_ps_exit("ERROR : INVALID SYNTAX", -1, 'r');
	if (pid <= 0)
		_nsx_ps_exit("ERROR : INVALID PID", -1, 'r');
	if (argv[2][0] == '\0')
		_nsx_ps_exit("ERROR : YOU CAN'T SEND EMPTY MESSAGE", -1, 'r');
}
