/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:17:31 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/07 11:14:34 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	_nsx_pc(char c)
{
	write(1, &c, 1);
}

void	_nsx_ps(char *str)
{
	while (*str)
		_nsx_pc(*str++);
}

void	_nsx_pd(int n)
{
	if (n == -2147483648)
		return ((void)_nsx_ps("-2147483648"));
	if (n == 0)
		return ((void)_nsx_ps("0"));
	if (n < 0)
	{
		n *= -1;
		_nsx_pc('-');
	}
	if (n <= 9)
		return ((void)_nsx_pc(n + 48));
	_nsx_pd(n / 10);
	_nsx_pd(n % 10);
}

void	_nsx_pcolor(char color)
{
	if (color == 'r')
		_nsx_ps("\033[1;31m");
	else
		if (color == 'g')
			_nsx_ps("\033[1;32m");
	else
		if (color == 'b')
			_nsx_ps("\033[1;34m");
	else
		_nsx_ps("\033[0m");
}

void	_nsx_ps_exit(char *_msg, int status, char color)
{
	_nsx_pcolor(color);
	_nsx_ps(_msg);
	_nsx_pcolor(0);
	exit(status);
}
