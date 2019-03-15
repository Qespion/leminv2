/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:50:29 by oespion           #+#    #+#             */
/*   Updated: 2018/10/29 19:41:43 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 1
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
typedef struct	s_struct
{
	char		*str;
}				t_struct;

typedef struct	s_printf
{
	va_list			ap;
	void			*str;
	char			*base_str;
	int				brett;
	int				increment;
	int				nbout;
	int				precision;
	int				width;
	int				negative;
	int				positive;
	int				zeros;
	int				blank;
	int				neg;
	int				sharp;
	int				nopesign;
	int				hexa;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
}				t_printf;

typedef	struct	s_list
{
	int				nb;
	int				p;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;


char			*ft_strchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strtrimfirst(char const *s);
int				ft_strcmp(char *s1, char *s2);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strnew(size_t size);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			*ft_strfjoin(char *s1, char *s2);
int				get_next_line(const int fd, char **line);
void			ft_memdel(void **ap);
char			*ft_itoa(int n);
char			*ft_strdup(const char *src);

int				ft_len_list(t_list *list);
t_list			**ft_insert_one(t_list **global, int lst_nb, int nb);
t_list			*ft_lstnew(int nb);
t_list			*ft_lstaddone(int nb, t_list *start, t_list *current);
void			ft_lstdelone(t_list *new);
void			ft_lstdel(t_list *lst);

int				ft_printf(const char *format, ...);
char			*ft_convert_base(uintmax_t nb, int base);
int				longlong_len(intmax_t nb);
const char		*end_of_int(const char *str);
int				uintmax_t_len(uintmax_t nb);
int				ft_strlen(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_strdel(char **as);
intmax_t		ft_atoi(const char *str);
void			printchar(t_printf *p, char letter);
void			ft_putcharnf(t_printf *p, char letter);
void			ft_putcharn(t_printf *p, char c);
void			ft_putnbr(intmax_t nb);
uintmax_t		ft_abs(long long nb);
void			printunb(t_printf*p, int maj);
void			printhexa(t_printf *p, int maj);
char			*ft_toupper(char *str);
void			printaddress(t_printf *p);
intmax_t		getnb(t_printf *p, int maj);
uintmax_t		getunb(t_printf *p, int maj);
void			ft_putstrn_hexa(t_printf *p, char *str, int maj);
void			printnb(t_printf *p, int maj);
void			ft_putnbr_uintmax(uintmax_t nb);
void			printoctal(t_printf *p, int maj);
int				bin_to_dec(char *bin);
char			*ft_strjoin(char *s1, char *s2);
void			write_with_precision(char *str, t_printf *p);
void			ft_putstrn(t_printf *p, char *str);
t_printf		*create_struct(void);
t_printf		*reset_struct(t_printf *p);
void			ft_get_arg(char letter, t_printf *p);
void			printunicode(t_printf *p);
char			*ft_convert_binary(uintmax_t nb);
void			ft_bzero(void *s, size_t n);
char			*ft_strcat(char *dest, const char *src);
void			ft_get_width(t_printf *p, uintmax_t nbr);
void			ft_get_precision(uintmax_t nbr, t_printf *p);
void			ft_pos(t_printf *p);
void			width_write(int max, int width_tmp, char spaces, t_printf *p);
void			printbinary(t_printf *p);
void			ft_putstrn_octal(t_printf *p, char *str);
int				checkunicode(t_printf *p);
void			break_bin(char *binary, t_printf *p, int brett);
void			print_uni_width(t_printf *p, int nlen);
void			printlstring(t_printf *p);
const char		*ft_precision(const char *format, t_printf *p);
const char		*ft_width(const char *format, t_printf *p);
const char		*ft_flags(const char *format, t_printf *p);
int				single_len(t_printf *p, int nb);
int				check_brett_tab(wchar_t *brett, t_printf *p);

#endif
