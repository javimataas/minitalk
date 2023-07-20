/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:55:26 by jmatas-p          #+#    #+#             */
/*   Updated: 2022/11/30 17:41:59 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long n, const char c)
{
	int		len;

	len = 0;
	if (n < 10)
		len += ft_putchar(n + 48);
	else if (n < 16)
	{
		if (c == 'x')
			len += ft_putchar(n + 87);
		if (c == 'X')
			len += ft_putchar(n + 55);
	}
	else
	{
		len += ft_printhex(n / 16, c);
		len += ft_printhex(n % 16, c);
	}
	return (len);
}
