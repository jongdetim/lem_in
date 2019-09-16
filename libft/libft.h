/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 17:38:47 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/16 19:09:59 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <float.h>
# include <stdarg.h>
# include <fcntl.h>

# define BUFF_SIZE 1000

typedef struct		s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}					t_list;

typedef struct		s_gnl_list
{
	int					fd;
	char				*content;
	struct s_gnl_list	*next;
}					t_gnl_list;

typedef struct		s_printf
{
	va_list	args;
	va_list	backup;
	int		precision;
	int		width;
	char	*format;
	char	type;
	int		ret;
	short	zero;
	short	dot;
	short	space;
	short	hash;
	short	minus;
	short	plus;
	char	length;
	void	(*arr[11])(struct s_printf*);
}					t_printf;

char				*ft_get_first_substr(char *str);
void				ft_error(char *str);
int					ft_hash_str(char *key, int size);
int					ft_isprime(int n);
int					ft_get_next_prime(int n);
char				*ft_strjoinfree(char *s1, char *s2);
void				process_int(t_printf *data);
void				parser(t_printf *data);
void				lowestll(t_printf *data);
void				flaghandler_o(t_printf *data, int len, short hash,
												unsigned long long d);
void				flaghandler_x(t_printf *data, int len, short hash,
												unsigned long long d);
void				dispatcher(t_printf *data);
void				build_dispatcher(t_printf *data);
void				init_data(t_printf *data);
void				set_argnum(t_printf *data, int d);
int					ft_printf(const char *restrict format, ...);
void				conv_c(t_printf *data);
void				conv_s(t_printf *data);
void				conv_p(t_printf *data);
void				conv_d(t_printf *data);
void				conv_u(t_printf *data);
void				conv_o(t_printf *data);
void				conv_x(t_printf *data);
void				conv_f(t_printf *data);
void				conv_prcnt(t_printf *data);
unsigned long long	typecast_u(t_printf *data, unsigned long long d);
char				*ft_strtoupper(char *str);
char				*ft_ftoa(long double f, int afterpoint);
int					ft_pythagoras(int x, int y);
int					ft_power(int num, int power);
int					ft_sqrt(unsigned int num);
int					ft_abs(int num);
void				ft_chararrfree(char ***arr);
int					ft_getnum(char *str, int num);
void				ft_putullnbr(unsigned long long n);
char				*ft_strtoupper(char *str);
void				ft_putllnbr(long long n);
char				*ft_ftoa(long double f, int afterpoint);
int					ft_digcountbase(long long n, int base);
int					ft_digcountbase_u(unsigned long long n, int base);
char				*ft_itoabase(unsigned long long n, int base);
int					get_next_line(const int fd, char **line);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_digcount(long long n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_iswhitespace(char c);
char				*ft_itoa(long long n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *rc, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_strcount(const char *s, char c);
void				ft_lstprintelemsizes(t_list *lst);

#endif
