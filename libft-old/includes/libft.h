/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:45:41 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/25 20:24:28 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

# define ASCII_OFFSET_NUM 48
# define ASCII_OFFSET_ALPHA 32
# define MAX_LINE 200000

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_format
{
	char			flags[9];
	int				width;
	int				precision;
	char			size[9];
	char			type;
}					t_format;

/*
** MEMORY FUNCTIONS
*/

void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** CONVERSION FUNCTIONS
*/

char				*ft_ftoa(double nb, int precision);
char				*ft_convert_base(unsigned long long nbr, char *base_to);
char				*ft_itoa(long long n);
int					ft_atoi(const char *str);

/*
** PRINTING FUNCTIONS
*/

int					ft_printf(const char *format, ...);
int					ft_putchar(char c);
int					ft_putstr(char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** STRINGS FUNCTIONS
*/

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, char *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strncat(char *dest, char *src, unsigned int nb);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big,
								const char *little,
								size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
int					get_next_line(int fd, char **line);

/*
** CHAR FUNCTIONS
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** LINKED LISTS FUNCTIONS
*/

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
								void *(*f)(void *),
								void (*del)(void *));

/*
** MATH FUNCTIONS
*/

int					ft_is_even(int nb);
double				ft_remainder(double numer, double denom);
int					ft_power(int nb, int power);
int					ft_sqrt(int nb);
long long			ft_abs_lg(long long n);
double				ft_abs_dl(double n);
size_t				get_size_dl(double nb);
size_t				get_size_lg(long long nb);
int					ft_round(double nb);

#endif
