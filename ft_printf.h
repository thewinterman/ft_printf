/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:28:40 by mwinter           #+#    #+#             */
/*   Updated: 2022/11/20 04:28:28 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# define FAIL -1
# define PASS 0
typedef struct s_fdata
{
	va_list	ap;
	int		len;
	char	type;
	char	*str;
	char	*sconv;
}			t_fdata;


int	ft_printf(const char *format, ...);

#endif
