/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:45:45 by amamy             #+#    #+#             */
/*   Updated: 2019/02/27 17:22:45 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"



int ft_printf(const char* str, ...) // fid a better name for the chat *
{
  va_list args;
  char    *buf;
  int     nb;

  if(!(buf = malloc(sizeof(char * 1000))))
    return
  va_start(args, str);
  nb = va_arg(args, int);
  ft_putstr(str);
  ft_putnbr(nb);
  ft_putstr("\n");
  return (0);
}
