/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:14:43 by iarrar            #+#    #+#             */
/*   Updated: 2023/04/26 18:13:37 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	size_unsigned(unsigned int n, unsigned int base)
{
	int				i;
	unsigned int	div;

	i = 0;
	div = n;
	if (div < base)
		return (i + 1);
	while (div >= base)
	{
		div = div / base;
		i++;
	}
	return (i + 1);
}

int	ft_putnbru_fd(unsigned int n, int fd)
{
	char			c;
	unsigned int	s;

	s = n;
	if (n > 9)
	{
		c = (n % 10) + '0';
		n /= 10;
		ft_putnbru_fd(n, fd);
		write(fd, &c, 1);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	return (size_unsigned(s, 10));
}
