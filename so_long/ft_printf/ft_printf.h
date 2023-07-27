/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:41:23 by iarrar            #+#    #+#             */
/*   Updated: 2023/04/26 18:27:43 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_strlen(const char *str);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbru_fd(unsigned int n, int fd);
int		ft_base(unsigned int n, char *str);
int		size_base(int n, int size);
int		ft_which_sign(va_list *args, char c);
int		ft_adresse(void *ptr);
int		ft_base_add(void *ptr, char *str);
int		ft_putnbru_base(unsigned int n, int fd, char *base);
int		ft_printf(const char *str, ...);
int		ft_countchar(const char *str, char c);
int		size_unsigned(unsigned int n, unsigned int base);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
