/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:22:25 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/07 13:31:34 by mait-elk         ###   ########.fr       */
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
