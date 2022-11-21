/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:39:46 by matwinte          #+#    #+#             */
/*   Updated: 2022/11/21 01:09:12 by matwinte         ###   ########.fr       */
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

	if (!fdata->str || !fdata->stmp)
		return (FAIL);
	s1 = fdata->str;
	fdata->str = ft_strjoin(s1, fdata->stmp);
	fdata->len += ft_strlen(fdata->stmp);
	free(s1);
	free(fdata->stmp);
	return (PASS);
}

int	ft_printf_process_sain(t_fdata *fdata, int i, const char *fmt)
{
	fdata->stmp = malloc(sizeof(char) * i + 1);
	if (!fdata->stmp)
		return (-1);
	ft_strlcpy(fdata->stmp, fmt, i + 1);
	return (ft_printf_append_str(fdata));
}

int (*ft_process[128])(t_fdata*);

void init_process(void)
{
	ft_memset(ft_process, 0, 128);
	ft_process['c'] = &ft_printf_process_char;
	ft_process['s'] = &ft_printf_process_sting;
	ft_process['p'] = &ft_printf_process_pointer;
	ft_process['d'] = &ft_printf_process_integer;
	ft_process['i'] = &ft_printf_process_integer;
	ft_process['u'] = &ft_printf_process_unsigned;
	ft_process['x'] = &ft_printf_process_hexa;
	ft_process['X'] = &ft_printf_process_hexa;
	ft_process['%'] = &ft_printf_process_percent;
}

int	ft_printf_engine(const char *fmt, t_fdata *fdata)
{
	int		i;

	while (*fmt)
	{
		i = 0;
		while (fmt[i] && fmt[i] != '%')
			i++;
		ft_printf_process_sain(fdata, i, fmt);
		if (fmt[i] == '%' && fmt[i +1] != '\0')
		{
			fdata->type = fmt[i + 1];
			if (ft_process[(int)fdata->type] == NULL)
				return (FAIL);
			(*ft_process[(int)fdata->type])(fdata);
			i += 2;
		}
		fmt += i;
	}
	ft_putstr_fd(fdata->str, 1);
	return (PASS);
}

int	ft_printf(const char *fmt, ...)
{
	t_fdata	fdata;

	if (!fmt)
		return (0);
	fdata.str = calloc(1, sizeof(char));
	if (!fdata.str)
		return (FAIL);
	va_start(fdata.ap, fmt);
	init_process();
	ft_printf_engine(fmt, &fdata);
	va_end(fdata.ap);
	free(fdata.str);
	return (fdata.len);
}

int	main(void)
{
	void	*p;

	p = NULL;
	ft_printf("te%ss%%t%c\n%i\n%u\n%X\n%p\n", "YOL111O", 'x', 1024, 2048, 1010101010, p);
	return (0);
}
