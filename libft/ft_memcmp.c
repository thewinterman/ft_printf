/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 04:30:22 by matwinte          #+#    #+#             */
/*   Updated: 2022/10/26 04:42:27 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem1;
	unsigned char	*mem2;

	mem1 = (unsigned char *) s1;
	mem2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while ((unsigned char) *mem1 == (unsigned char) *mem2 && --n)
	{
		mem1++;
		mem2++;
	}
	return ((unsigned char) *mem1 - (unsigned char) *mem2);
}
