/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:03:28 by matwinte          #+#    #+#             */
/*   Updated: 2022/11/21 01:13:44 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*d;

	d = (char *) s;
	while (n--)
	{
		d[n] = c;
	}
	return (s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && --size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*s;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	while (*s1)
	{
		s[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		s[i++] = *s2;
		s2++;
	}
	s[i] = '\0';
	return (s);
}

size_t	ft_ul_char_len(unsigned long n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ul_to_str(unsigned long nb, size_t len)
{
	char	*s;

	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len--] = '\0';
	if (nb == 0)
		*s = '0';
	while (nb)
	{
		s[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (s);
}

char	*ft_ultoa(unsigned long n)
{
	size_t		len;

	if (n)
		len = ft_ul_char_len(n);
	else
		len = 1;
	return (ul_to_str(n, len));
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (str);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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
