/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmalkaw <abmalkaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:03:46 by abmalkaw          #+#    #+#             */
/*   Updated: 2026/10/03 18:03:46 by abmalkaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char format)
{
	char	*base;
	int		count;
	int		check;

	count = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		check = ft_puthex(n / 16, format);
		if (check == -1)
			return (-1);
		else
			count += check;
	}
	if (write(1, &base[n % 16], 1) != -1)
		count++;
	else
		return (-1);
	return (count);
}
