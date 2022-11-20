/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:28:24 by mwinter           #+#    #+#             */
/*   Updated: 2022/11/20 04:42:03 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
# Syntax of a conversion specification
%[$][flags][width][.precision][length modifier]conversion

## Conversion (Minimum required)
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/

int	ft_printf_append_str(t_fdata *fdata)
{
	char	*s1;

	s1 = fdata->str;
	fdata->str = ft_strjoin(s1, fdata->sconv);
	fdata->len += ft_strlen(fdata->sconv);
	free(s1);
	free(fdata->sconv);
	return (PASS); // to check !!!
}

int	ft_printf_process_sain(t_fdata *fdata, int i, const char *fmt)
{
	fdata->sconv = malloc(sizeof(char) * i + 1);
	if (!fdata->sconv)
		return (-1);
	ft_strlcpy(fdata->sconv, fmt, i + 1);
	return (ft_printf_append_str(fdata));
}

int	ft_printf_process_char(t_fdata *fdata)
{
	fdata->sconv = malloc(sizeof(char) * 2);
	if (!fdata->sconv)
		return (FAIL);
	fdata->sconv[0] = va_arg(fdata->ap, int);
	fdata->sconv[1] = '\0';
	return (ft_printf_append_str(fdata));
}

int	ft_printf_process_sting(t_fdata *fdata)
{
	fdata->sconv = ft_strdup(va_arg(fdata->ap, char *));
	if (!fdata->sconv)
		return (FAIL);
	return (ft_printf_append_str(fdata));
}

/*int	ft_printf_process_pointer(t_fdata *fdata);

int	ft_printf_process_integer(t_fdata *fdata);

int	ft_printf_process_unsigned(t_fdata *fdata);

int	ft_printf_process_hexa(t_fdata *fdata);

int	ft_printf_process_percent(t_fdata *fdata);
*/

int	ft_printf_convert_type(t_fdata *fdata, char type)
{
	fdata->type = type;
	if (type == 'c')
		ft_printf_process_char(fdata);
	else if (type == 's')
		ft_printf_process_sting(fdata);
/*	else if (type == 'p')
		ft_printf_process_pointer(fdata);
	else if (type == 'd' || type == 'i')
		ft_printf_process_integer(fdata);
	else if (type == 'u')
		ft_printf_process_unsigned(fdata);
	else if (type == 'x' || type == 'X')
		ft_printf_process_hexa(fdata);
	else if (type == '%')
		ft_printf_process_percent(fdata);
*/
	else
		write(1, "wtf?", 4); //to change
	return (PASS);
}

int	ft_printf_engine(const char *fmt, t_fdata *fdata)
{
	int	i;

	while (*fmt)
	{
		i = 0;
		while (fmt[i] && fmt[i] != '%')
			i++;
		ft_printf_process_sain(fdata, i, fmt);
		if (fmt[i] == '%')
		{
			ft_printf_convert_type(fdata, fmt[i + 1]);
			i += 2;
		}
		fmt += i;
	}
	ft_putstr_fd(fdata->str, 1);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	t_fdata	*fdata;

	if (!fmt)
		return (0);
	fdata = malloc(sizeof(t_fdata));
	if (!fdata)
		return (FAIL);
	fdata->str = calloc(1, sizeof(char));
	if (!fdata->str)
		return (FAIL);
	va_start(fdata->ap, fmt);
	ft_printf_engine(fmt, fdata);
	len = fdata->len;
	va_end(fdata->ap);
	free(fdata->str);
	free(fdata);
	return (len);
}

int	main(void)
{
	ft_printf("te%sst%c\n", "YOL111O", 'x');
	return (0);
}
