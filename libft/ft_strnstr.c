/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 04:45:30 by matwinte          #+#    #+#             */
/*   Updated: 2022/10/26 21:48:59 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] == big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == '\0' && i + j - 1 < len)
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
