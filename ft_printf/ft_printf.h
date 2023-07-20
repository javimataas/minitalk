/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:02:39 by jmatas-p          #+#    #+#             */
/*   Updated: 2022/11/30 17:42:14 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_printprct(void);
int			ft_printnbr(int n);
int			ft_printchar(int c);
int			ft_printstr(char *str);
int			ft_printf(const char *str, ...);
int			ft_printnbr_unsigned(unsigned int n);
int			ft_printptr(void *ptr);
int			ft_printhex(unsigned long n, const char c);
int			ft_processformat(const char c, va_list argl);

void		ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_num_len(unsigned int n);
char		*ft_itoa(int n);
char		*ft_uitoa(unsigned int n);

#endif
