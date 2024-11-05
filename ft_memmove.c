/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernstdevan <ernstdevan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:28:57 by ernstdevan        #+#    #+#             */
/*   Updated: 2024/10/30 23:47:10 by ernstdevan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= (size_t)ft_strlen((char *)src) - (size_t)ft_strlen((char *)dest))
	{
		while (((unsigned char *)dest)[i] != '\0' && i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		if ((size_t)ft_strlen((char *) dest) < n)
			n -= (ft_strlen((char *) src) - ft_strlen((char *)dest));
		i = n - 1;
		n--;
		while ((int)i >= 0)
		{
			((unsigned char *) dest)[i] = ((unsigned char *)src)[n];
			i--;
			n--;
		}
	}
	return ((unsigned char *)dest);
}
