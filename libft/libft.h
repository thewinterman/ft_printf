/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:49:29 by matwinte          #+#    #+#             */
/*   Updated: 2022/11/20 02:00:58 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* ************************************************************************** */
/*		Output																  */
/* ************************************************************************** */

/*output a characters in fd*/
void	ft_putchar_fd(char c, int fd);
/*output string in fd*/
void	ft_putstr_fd(char *s, int fd);
/*output string with endl in fd*/
void	ft_putendl_fd(char *s, int fd);
/*output number in fd*/
void	ft_putnbr_fd(int n, int fd);

/* ************************************************************************** */
/*		Char																  */
/* ************************************************************************** */

// checks ----------------------------------------------------------------------
/*checks for an alphabetic character*/
int		ft_isalpha(int c);
/*checks for a digit (0 through 9).*/
int		ft_isdigit(int c);
/*checks for an alphanumeric character*/
int		ft_isalnum(int c);
/*checks whether c is ascii*/
int		ft_isascii(int c);
/*checks for any printable character including space.*/
int		ft_isprint(int c);

// convert ---------------------------------------------------------------------
/*convert lowercase to uppercase*/
int		ft_toupper(int c);
/*convert uppercase to lowercase*/
int		ft_tolower(int c);

/* ************************************************************************** */
/*		String																  */
/* ************************************************************************** */

// checks ----------------------------------------------------------------------

/*calculate the char length of an int*/
size_t	ft_int_char_len(int n);
/*calculate the length of a string*/
size_t	ft_strlen(const char *s);
/*locate first occurrence character in string*/
char	*ft_strchr(const char *s, int c);
/*locate last occurrence character in string*/
char	*ft_strrchr(const char *s, int c);
/*locate a substring in a string*/
char	*ft_strnstr(const char *big, const char *little, size_t len);
/*size bounded comparaison of two strings*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// copy / duplicate ------------------------------------------------------------

/*duplicate a string*/
char	*ft_strdup(const char *s);
/*size-bounded string copying*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/*size-bounded string concatenation*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);
/*returns a substring begins at index ’start’ and is of maximum size ’len’*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
/*returns a copy of two string concatenated*/
char	*ft_strjoin(char const *s1, char const *s2);
/*returns a copy of str while removing char in set from begging and end*/
char	*ft_strtrim(char const *s1, char const *set);
/*returns an arr of str obtained by splitting ’s’ using ’c’ as a delimiter.*/
char	**ft_split(char const *s, char c);
/*copy a string modified by fcn*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// convert/modify --------------------------------------------------------------

/*convert a string to an integer*/
int		ft_atoi(const char *nptr);
/*convert an integer to a string*/
char	*ft_itoa(int n);
/*apply function on all char of str*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ************************************************************************** */
/*		Memory																  */
/* ************************************************************************** */

// checks ----------------------------------------------------------------------

/*scan memory for a character*/
void	*ft_memchr(const void *s, int c, size_t n);
/*compare memory areas*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// modify ----------------------------------------------------------------------

/*zero a byte string*/
void	ft_bzero(void *s, size_t n);
/*fill memory with a constant byte*/
void	*ft_memset(void *s, int c, size_t n);
/*allocate memory & fill with 0*/
void	*ft_calloc(size_t nmemb, size_t size);

// copy / duplicate ------------------------------------------------------------

/*copy memory area*/
void	*ft_memcpy(void *dest, const void *src, size_t n);
/*copy memory area*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/* ************************************************************************** */
/*		List																  */
/* ************************************************************************** */

typedef struct s_list
{
	void	*content;
	void	*next;
}					t_list;

// checks ----------------------------------------------------------------------
/*get size of a list*/
int		ft_lstsize(t_list *lst);
/*get last node of a list*/
t_list	*ft_lstlast(t_list *lst);

// creation --------------------------------------------------------------------

/*create new list node*/
t_list	*ft_lstnew(void *content);

// addition --------------------------------------------------------------------

/*add node at the front of the list*/
void	ft_lstadd_front(t_list **lst, t_list *new);
/*add node at the back of the list*/
void	ft_lstadd_back(t_list **lst, t_list *new);

// deletion --------------------------------------------------------------------

/*delete one node of the list & clear content with provided fcn*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/*clear list & content with provided fcn*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

// modification ----------------------------------------------------------------

/*apply fcn to the content of a list*/
void	ft_lstiter(t_list *lst, void (*f)(void *));
/*duplicate a list with content modified by f*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
