/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:08:09 by etong             #+#    #+#             */
/*   Updated: 2024/06/18 11:08:03 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printf(const char *format, ...);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int nb);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_printhex(void *ptr, char *base);

#endif