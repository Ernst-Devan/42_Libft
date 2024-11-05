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

void    ft_memmove(void *dest, const void *src, size_t n)
{
    size_t     i;

    i = 0;
    // no overlapse
    if (n <= (size_t)ft_strlen((char *)src) - (size_t)ft_strlen((char *)dest))
    {
        while (((char *)dest)[i] != '\0' && i < n)
        {
           ((char *)dest)[i] = ((char *)src)[i];
            i++;
        }
    }
    // overlapse
    else
    {
        if ((size_t)ft_strlen((char *)dest) < n)
            n -= ft_strlen((char *)src) - ft_strlen((char *)dest);
        i = ft_strlen((char *)src) - 1;
        while ((int)i >= 1)
        {
            ((char *)dest)[i] = ((char *)src)[n];
            i--;
            n--;
        }
    }
}
