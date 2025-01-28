/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:53:24 by dernst            #+#    #+#             */
/*   Updated: 2025/01/28 23:20:04 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"
#include "errno.h"

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	const char		*s;
	unsigned long	acc;
	int				c;
	unsigned long	cutoff;
	int				cutlim;
	int				any;
	int				neg;

	s = nptr;
	neg = 0;
	c = *s++;
	while (ft_isspace(c))
		c = *s++;
	if (c == '-')
	{
		neg = 1;
		c = *s++;	
	}
	else if(c == '+')
	{
		c = *s++;
	}
	if (base == 0 || (base == 16 && c == '0' && (*s == 'x' || *s == 'X')))
	{
		c = s[1];
		s += 2;
		base = 16;
	}
	if (base == 0)
	{
		if (c == 0)
			base = 8;
		else
			base = 10;
	}
	
	if (neg)
		cutoff = -(unsigned long)LONG_MIN;
	else
		cutoff = LONG_MAX;
	
	cutlim = cutoff % (unsigned long)base;
	cutoff /= (unsigned long)base;

	acc = 0;
	any = 0;
	while (*s != '\0')
	{
		if (ft_isdigit(c))
			c -= '0';
		else if (ft_isalpha(c))
		{
			if (ft_isupper(c))
				c -= 'A' - 10;
			else
				c -= 'a' - 10;
		}
		else
			break;
		if (c >= base)
			break;
		if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
			any = -1;
		else
		{
			any = 1;
			acc *= base;
			acc += c;
		}
		c = *s++;
	}
	
	if (any < 0)
	{
		if (neg)
			acc = LONG_MIN;
		else
			acc = LONG_MAX;
	} else if (neg)
		acc = -acc;
	if (endptr != 0)
	{
		if (any)
			*endptr = (char *) s - 1;
		else
			*endptr = (char *)nptr; 
	}
	return (acc);
}

int	main(void)
{
	char test[15] = " 21474836487\0";
	char **nptr = NULL;
	int number;
	number = ft_strtol(test, nptr , 10);
	ft_printf("%d", number);
}