/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_csdiupercent.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:46:30 by matwinte          #+#    #+#             */
/*   Updated: 2022/11/21 00:46:56 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_process_char(t_fdata *fdata)
{
	fdata->stmp = malloc(sizeof(char) * 2);
	if (!fdata->stmp)
		return (FAIL);
	fdata->stmp[0] = va_arg(fdata->ap, int);
	fdata->stmp[1] = '\0';
	return (ft_printf_append_str(fdata));
}

int	ft_printf_process_sting(t_fdata *fdata)
{
	fdata->stmp = ft_strdup(va_arg(fdata->ap, char *));
	if (!fdata->stmp)
		return (FAIL);
	return (ft_printf_append_str(fdata));
}

int	ft_printf_process_integer(t_fdata *fdata)
{
	fdata->stmp = ft_itoa(va_arg(fdata->ap, int));
	return (ft_printf_append_str(fdata));
}

int	ft_printf_process_unsigned(t_fdata *fdata)
{
	fdata->stmp = ft_ultoa(va_arg(fdata->ap, unsigned long));
	return (ft_printf_append_str(fdata));
}

int	ft_printf_process_percent(t_fdata *fdata)
{
	fdata->stmp = malloc(sizeof(char) * 2);
	if (!fdata->stmp)
		return (FAIL);
	fdata->stmp[0] = '%';
	fdata->stmp[1] = '\0';
	return (ft_printf_append_str(fdata));
}
