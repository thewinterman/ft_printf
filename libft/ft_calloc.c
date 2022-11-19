/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 04:55:51 by matwinte          #+#    #+#             */
/*   Updated: 2022/10/26 22:15:30 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (INT_MAX < nmemb * size)
		p = NULL;
	else
		p = malloc(nmemb * size);
	if (p == NULL)
		return (p);
	ft_bzero(p, nmemb * size);
	return (p);
}
