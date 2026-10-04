/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmalkaw <abmalkaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:04:07 by abmalkaw          #+#    #+#             */
/*   Updated: 2026/10/03 18:04:07 by abmalkaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	long long	nb;
	char		c;
	int			counter;
	int			check;

	nb = n;
	counter = 0;
	if (nb >= 10)
	{
		check = ft_put_unsigned_nbr_fd(nb / 10, fd);
		if (check == -1)
			return (-1);
		else
			counter += check;
		nb = nb % 10;
	}
	c = nb + '0';
	if (write(fd, &c, 1) != -1)
		counter++;
	else
		return (-1);
	return (counter);
}
