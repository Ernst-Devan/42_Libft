/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:45:21 by ernstdevan        #+#    #+#             */
/*   Updated: 2024/11/09 18:30:18 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		count++;
	}
	return (count);
}
//static void	cleanup()
//{

//}

static void	is_set(char const *s, char c, int *i, char **result)
{
	int	j;
	int	m;

	j = 0;
	m = 0;
	while (s[*i] && j < count_words(s, c))
	{
		if (s[*i] != c)
			result[j][m++] = s[*i];
		else
		{
			while (s[*i] == c)
					(*i)++;
			(*i)--;
			result[j][m] = '\0';
			m = 0;
			if (j >= count_words(s, c))
				break;
			j++;
		}
		(*i)++;
	}
	if (j < count_words(s , c))
		result[j][m] = '\0';
}


static void 	next_words(const char *s, int *j, int *count)
{
	while (s[*j] <= 32 && s[*j] != '\0')
		(*j)++;
	while ((s[*j] >= 33 && s[*j] <= 126) && s[*j] != '\0')
		{
			(*j)++;
			(*count)++;
		}
}
char	**ft_split(char const *s, char c)
{
	char	**result;
	int	i;
	int	j;
	int	count;

	if (ft_strlen(s) == 0)
		return(NULL);
	i = 0;
	j = 0;
	count  = 0;
	result = malloc(sizeof(char) * (count_words(s,c) + 1));
	while (i < count_words(s, c))
	{
		next_words(s, &j, &count);
		result[i] = malloc(sizeof(char) * (count + 1));
		i++;
		count = 0;
	}
	i = 0;
	while (s[i] == c)
		i++;
	is_set(s, c, &i, result);
	return (result);
}
