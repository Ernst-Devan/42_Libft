/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:07:42 by dernst            #+#    #+#             */
/*   Updated: 2024/11/09 18:51:01 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Check negatives values

static int	intlen(long int n)
{
	unsigned int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	strreverse(char *str, int sign)
{
	size_t		i;
	size_t	j;
	char	temp;

	i = 0 + sign;
	j = ft_strlen(str) - 1;
	while (i <= (ft_strlen(str) / 2) - 1 + sign)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

static void	manage_sign(int *sign, size_t *i, long int *num)
{
	if (*num < 0)
	{
		*sign = 1;
		*num *= -1;
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	size_t			i;
	int		sign;
	char		*result;
	long int	num;

	num = n;
	if (num == 0)
		return ("0");
	sign = 0;
	i = 0;
	manage_sign(&sign, &i, &num);
	result = malloc(sizeof(int) * (intlen(num) + sign + 1));
	if (!result)
		return (NULL);
	while (num > 0)
	{
		result[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	result[i] = '\0';
	if (sign == 1)
		result[0] = '-';
	strreverse(result, sign);
	return (result);
}