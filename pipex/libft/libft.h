/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:12:53 by bschoeff          #+#    #+#             */
/*   Updated: 2022/08/25 13:13:11 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_node
{
	int				content;
	int				index;
	int				position;
	int				tg_pos;
	int				cost_a;
	int				cost_b;
	int				cost;
	struct s_node	*next;
}				t_node;

/* Libft */
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *c);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
void		ft_strcpy(char **dst, const char *src);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nelem, size_t elsize);
char		*ft_strdup(const char *s);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		**ft_split(const char *s, char c);
char		**ft_split_pipex(const char *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
t_node		*ft_lstnew_ps(int nb);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_front_ps(t_node **lst, t_node *new);
int			ft_lstsize(t_list *lst);
int			ft_lstsize_ps(t_node *lst);
t_list		*ft_lstlast(t_list *lst);
t_node		*ft_lstlast_ps(t_node *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_back_ps(t_node **lst, t_node *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstclear_ps(t_node **lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_secure_atoi(const char *str);
int			ft_isspace(int c);

/* Printf */
int			ft_printf(const char *fmt, ...);
int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putptr(unsigned long n, char *base, int start);
int			ft_putnbr(int n);
int			ft_put_unbr(unsigned int n);
int			ft_puthx(unsigned long n, char *base);

/* Get next line */
char		*get_next_line(int fd);

#endif
