/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:09:49 by iarrar            #+#    #+#             */
/*   Updated: 2023/04/26 18:12:03 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_which_sign(va_list *args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar_fd(va_arg(*args, int), 1);
	if (c == 's')
		i = ft_putstr_fd(va_arg(*args, char *), 1);
	if (c == 'p')
		i = ft_adresse(va_arg(*args, void *));
	if (c == 'd')
		i = ft_putnbr_fd(va_arg(*args, int), 1);
	if (c == 'i')
		i = ft_putnbr_fd(va_arg(*args, int), 1);
	if (c == 'u')
		i = ft_putnbru_fd(va_arg(*args, unsigned int), 1);
	if (c == 'x')
		i = ft_putnbru_base(va_arg(*args, int), 1, "0123456789abcdef");
	if (c == 'X')
		i = ft_putnbru_base(va_arg(*args, int), 1, "0123456789ABCDEF");
	if (c == '%')
		i = ft_putchar_fd('%', 1);
	return (i);
}
