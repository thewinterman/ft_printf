/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:24:26 by matwinte          #+#    #+#             */
/*   Updated: 2022/10/31 21:54:53 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_to_str_arr(char *s, long int nb)
{
	size_t	len;

	if (nb)
		len = ft_int_char_len(nb);
	else
		len = 1;
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
}

void	ft_putnbr_fd(int n, int fd)
{
	char	s[12];

	int_to_str_arr(s, n);
	ft_putstr_fd(s, fd);
}
