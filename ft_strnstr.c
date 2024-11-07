/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:51:47 by ernstdevan        #+#    #+#             */
/*   Updated: 2024/11/07 21:37:29 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strlen((char *)little) == 0)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			while (big[i] == little[j] && i < len && big[i] != '\0')
			{
				i++;
				j++;
			}
			if ((ft_strlen((char *)little)) == j)
				return ((char *)big + i - j);
			i -= j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
