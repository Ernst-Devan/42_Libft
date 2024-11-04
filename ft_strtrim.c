/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernstdevan <ernstdevan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:23:44 by ernstdevan        #+#    #+#             */
/*   Updated: 2024/11/02 18:23:29 by ernstdevan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Problem with space : start / end

#include "libft.h"

int	check_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*result;

	i = 0;
	while (check_set(s1[i], (char *) set) == 1 && s1[i] != '\0')
		i++;
	start = i;
	i = ft_strlen((char *)s1) - 1;
	while (check_set(s1[i], (char *) set) == 1 && i >= 0)
		i--;
	end = i;
	result = malloc((end - start) + 2);
	if (!result)
		return (NULL);
	i = 0;
	while ((i + start <= end) && (end - start + 1 >= 0))
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
