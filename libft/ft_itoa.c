/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:28:58 by matwinte          #+#    #+#             */
/*   Updated: 2022/10/31 21:39:21 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_int_char_len(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*int_to_str(long int nb, size_t len)
{
	char	*s;

	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len--] = '\0';
	if (nb < 0)
	{
		*s = '-';
		nb *= -1;
	}
	else if (nb == 0)
		*s = '0';
	while (nb)
	{
		s[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	size_t		len;

	if (n)
		len = ft_int_char_len(n);
	else
		len = 1;
	return (int_to_str(n, len));
}
