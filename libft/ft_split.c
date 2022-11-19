/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:10:14 by matwinte          #+#    #+#             */
/*   Updated: 2022/11/08 00:24:57 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i++])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		w++;
	}
	return (w);
}

char	**splitter(const char *s, char c, char **p, size_t w)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (w--)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i] != '\0')
			i++;
		p[j++] = ft_substr(s, 0, i);
		s += i;
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	size_t	w;
	char	**p;

	if (s == NULL || *s == '\0')
	{
		p = malloc(sizeof(char **));
		if (p == NULL)
			return (NULL);
		p[0] = NULL;
		return (p);
	}
	w = word_count(s, c);
	p = malloc(sizeof(char *) * (w + 1));
	if (p == NULL)
		return (NULL);
	return (splitter(s, c, p, w));
}
