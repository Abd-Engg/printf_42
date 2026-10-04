/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmalkaw <abmalkaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:04:15 by abmalkaw          #+#    #+#             */
/*   Updated: 2026/10/03 23:00:56 by abmalkaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	string(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		str = "(null)";
	counter += ft_putstr_fd(str, 1);
	return (counter);
}

static int	pointer(unsigned long temp)
{
	int	counter;
	int	check;

	counter = 0;
	if (!temp)
		counter += ft_putstr_fd("(nil)", 1);
	else
	{
		check = ft_putstr_fd("0x", 1);
		if (check == -1)
			return (-1);
		counter = ft_puthex(temp, 'x');
		if (counter == -1)
			return (-1);
		counter += check;
	}
	return (counter);
}

static int	check(char c, va_list ap)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (c == 'u')
		return (ft_put_unsigned_nbr_fd(va_arg(ap, unsigned int), 1));
	else if (c == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), 'x'));
	else if (c == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), 'X'));
	else if (c == 's')
		return (string(va_arg(ap, char *)));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	else if (c == 'p')
		return (pointer(va_arg(ap, unsigned long)));
	else if (c == '%')
		return (ft_putchar_fd(c, 1));
	return (0);
}

static int	for_norm(const char *s, va_list ap)
{
	int	counter;
	int	i;
	int	res;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			res = check(s[i + 1], ap);
			i += 2;
		}
		else
		{
			if (s[i] == '%' && s[i + 1] == '\0')
				return (-1);
			res = ft_putchar_fd(s[i], 1);
			i++;
		}
		if (res == -1)
			return (-1);
		counter += res;
	}
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		counter;

	if (!s)
		return (-1);
	va_start(ap, s);
	counter = for_norm(s, ap);
	va_end(ap);
	return (counter);
}
