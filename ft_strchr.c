/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernstdevan <ernstdevan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:57:09 by ernstdevan        #+#    #+#             */
/*   Updated: 2024/10/15 15:37:44 by ernstdevan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((int)s[i] == c)
		{
			return (& (((char *)s)[i]));
		}
		i++;
	}
	if (c == '\0')
	{
		return (& (((char *)s)[i]));
	}
	return (NULL);
}
