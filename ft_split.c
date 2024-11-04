/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernstdevan <ernstdevan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:45:21 by ernstdevan        #+#    #+#             */
/*   Updated: 2024/11/04 16:21:22 by ernstdevan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	count_words(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] <= 32)
		i++;
	while (s[i] != '\0')
	{
		while ((s[i] >= 33 && s[i] <= 126) && s[i] != '\0')
			i++;
		while (s[i] <= 32 && s[i] != '\0')
			i++;
		count++;
	}
	return (count);
}


void	cleanup()
{

}

void	is_set(char const *s, char c, int *i, char **result)
{
	int	j;
	int	m;

	j = 0;
	m = 0;
	while (s[*i] != '\0')
	{
		if (s[*i] != c)
		{
			result[j][m] = s[*i];
			m++;
		}
		if (s[*i] == c)
		{
			while (s[*i] == c)
				(*i)++;
			result[j][m] = '\0';
			j++;
			m = 0;
			result[j][m] = s[*i];
		}
		(*i)++;
	}
}


void 	next_words(char *s, int *j, int *count)
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

	(void)c;

	i = 0;
	j = 0;
	count  = 0;
	result = malloc(sizeof(char *) * (count_words((char *)s) + 1));
	while (i < count_words((char *)s))
	{
		next_words((char *)s, &j, &count);
		result[i] = malloc(sizeof(char) * (count + 1));
		(i)++;
		count = 0;
	}
	i = 0;
	while (s[i] == c)
		i++;
	is_set(s, c, &i, result);
	return (result);
}

int	main(void)
{
	char **test;
	
	test = ft_split("   Je  veux     savoir", ' ');
	
	int i;

	i = 0;
	while (i < 3)
	{
		printf("%s \n", test[i]);
		i++;
	}
}
