/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_pxX.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:43:03 by matwinte          #+#    #+#             */
/*   Updated: 2022/11/21 00:53:36 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_n_base_len(unsigned long n, size_t len_base)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= len_base;
		i++;
	}
	return (i);
}

int	ft_printf_process_pointer(t_fdata *fdata)
{
	char			*base;
	unsigned long	n;
	size_t			i;

	base = "0123456789abcedf";
	n = va_arg(fdata->ap, unsigned long);
	i = ft_n_base_len(n, 16) + 2;
	fdata->stmp = malloc(sizeof(char) * i + 1);
	if (!fdata->stmp)
		return (FAIL);
	fdata->stmp[i] = '\0';
	fdata->stmp[0] = '0';
	fdata->stmp[1] = 'x';
	if (n == 0)
		fdata->stmp[--i] = '0';
	while (n)
	{
		fdata->stmp[--i] = base[n % 16];
		n /= 16;
	}
	return (ft_printf_append_str(fdata));
}

int	ft_printf_process_hexa(t_fdata *fdata)
{
	char			*base;
	size_t			len_base;
	unsigned long	n;
	size_t			i;

	if (fdata->type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcedf";
	len_base = ft_strlen(base);
	n = va_arg(fdata->ap, unsigned long);
	i = ft_n_base_len(n, len_base);
	fdata->stmp = malloc(sizeof(char) * i + 1);
	if (!fdata->stmp)
		return (FAIL);
	fdata->stmp[i] = '\0';
	while (n)
	{
		fdata->stmp[--i] = base[n % len_base];
		n /= len_base;
	}
	return (ft_printf_append_str(fdata));
}
