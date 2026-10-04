/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmalkaw <abmalkaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:03:12 by abmalkaw          #+#    #+#             */
/*   Updated: 2026/10/03 18:03:12 by abmalkaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long long	nb;
	char		c;
	int			counter;
	int			check;

	nb = n;
	counter = 0;
	if (nb < 0)
	{
		nb = -nb;
		counter += write(fd, "-", 1);
	}
	if (nb >= 10)
	{
		check = ft_putnbr_fd(nb / 10, fd);
		if (check == -1)
			return (-1);
		else
			counter += check;
		nb = nb % 10;
	}
	c = nb + '0';
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (counter + 1);
}
