/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernstdevan <ernstdevan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:04:10 by ernstdevan        #+#    #+#             */
/*   Updated: 2024/10/15 15:40:29 by ernstdevan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last_i;

	i = 0;
	last_i = -1;
	while (s[i] != '\0')
	{
		if ((int)s[i] == c)
			last_i = i;
		i++;
	}
	if (c == '\0')
	{
		return (& (((char *)s)[i]));
	}
	if (last_i == -1)
		return (NULL);
	return (& (((char *)s)[last_i]));
}
