/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 04:54:02 by matwinte          #+#    #+#             */
/*   Updated: 2022/10/26 21:00:45 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (((8 < *nptr && *nptr < 14) || *nptr == ' ') && *nptr != '\0')
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while ((47 < *nptr && *nptr < 58) && *nptr != '\0')
	{
		i += *nptr - 48;
		nptr++;
		if (*nptr == '\0' || !(47 < *nptr && *nptr < 58))
			break ;
		i *= 10;
	}
	return (i * sign);
}
