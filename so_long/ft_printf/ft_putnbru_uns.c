/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_uns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:24:33 by iarrar            #+#    #+#             */
/*   Updated: 2023/04/26 18:25:43 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putnbru_base(unsigned int n, int fd, char *base)
{
	char			c;
	unsigned int	i;
	unsigned int	s;

	s = n;
	i = (unsigned int)ft_strlen(base);
	if (n > i - 1)
	{
		c = base[(n % i)];
		n /= i;
		ft_putnbru_base(n, fd, base);
		write(fd, &c, 1);
	}
	else
	{
		c = base[n];
		write(fd, &c, 1);
	}
	return (size_unsigned(s, ft_strlen(base)));
}
