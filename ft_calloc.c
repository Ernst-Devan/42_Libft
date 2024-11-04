/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernstdevan <ernstdevan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:28:48 by ernstdevan        #+#    #+#             */
/*   Updated: 2024/10/27 22:27:54 by ernstdevan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;

	if (nmemb == 0 || size == 0 || (nmemb * size) > 2147483647)
	{
		result = malloc(1);
		return (result);
	}
	result = malloc(nmemb * size);
	if (!result)
		return (result);
	result = ft_memset(result, 0, nmemb);
	return (result);
}
