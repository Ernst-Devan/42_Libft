/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:31:24 by ernstdevan        #+#    #+#             */
/*   Updated: 2024/11/12 22:47:14 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	over_under_check(const char *nptr, int sign, size_t *z)
{
	size_t	i;
	size_t	count;

	i = *z;
	count = 0;
	while (nptr[i] == 48)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		count++;
		i++;
	}
	if (count >= 20)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (over_under_check(nptr, sign, &i) == -1
		|| over_under_check(nptr, sign, &i) == 0)
		return (over_under_check(nptr, sign, &i));
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
