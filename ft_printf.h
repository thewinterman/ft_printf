/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:28:40 by mwinter           #+#    #+#             */
/*   Updated: 2022/11/21 01:14:20 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# define FAIL -1
# define PASS 0

typedef struct s_fdata
{
	va_list	ap;
	int		len;
	char	type;
	char	*str;
	char	*stmp;
	int		status;
}			t_fdata;

int		ft_printf(const char *format, ...);
int		ft_printf_append_str(t_fdata *fdata);

//ft_printf_process_csdiupercent.c

int		ft_printf_process_char(t_fdata *fdata);
int		ft_printf_process_sting(t_fdata *fdata);
int		ft_printf_process_integer(t_fdata *fdata);
int		ft_printf_process_unsigned(t_fdata *fdata);
int		ft_printf_process_percent(t_fdata *fdata);

//ft_printf_process_pxX.c

int	ft_printf_process_pointer(t_fdata *fdata);
int	ft_printf_process_hexa(t_fdata *fdata);

//ft_printf_libft.c
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_ultoa(unsigned long n);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);

#endif
