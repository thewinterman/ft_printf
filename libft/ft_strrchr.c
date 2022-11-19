/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:47:44 by matwinte          #+#    #+#             */
/*   Updated: 2022/11/07 21:28:11 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long int	i;

	i = ft_strlen(s) + 1;
	while (--i > -1)
		if (s[i] == (unsigned char) c)
			return ((char *) s + i);
	return (NULL);
}
