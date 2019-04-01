/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:04:20 by amamy             #+#    #+#             */
/*   Updated: 2019/04/01 16:45:12 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_nb_neg(char *str, long n, int base)
{
	size_t	counter;
	size_t	end;
	int		q;

	counter = 0;
	str[counter] = '-';
	end = ft_nb_len_base(n, base);
	n = -n;
	str[end] = '\0';
	counter = ft_nb_len_base(n, base);
	while (n != 0)
	{
		q = n % base;
		if (q <= 9)
			str[counter] = (n % base) + 48;
		if (q > 9)
			str[counter] = (n % base) + 55;
		n = n / base;
		counter--;
	}
	return (str);
}

char			*ft_itoa_base(long long n, int base)
{
	char	*str;
	long	counter;
	int		q;

	counter = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_nb_len_base(n, 10) + 1)))
		return (NULL);
	if (n == 0 || n == -0)
		return ("0");
	if (n > 0)
		counter = ft_nb_len_base(n, base) - 1;
	if (n < 0)
		return (ft_nb_neg(str, n, base));
	str[counter + 1] = '\0';
	while (n != 0)
	{
		q = n % base;
		if (q <= 9)
			str[counter] = (n % base) + 48;
		if (q > 9)
			str[counter] = (n % base) + 55;
		n = n / base;
		counter--;
	}
	return (str);
}

static int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base_mode(long long v, unsigned int b, int m)
{
	char			*str;
	char			*tab;
	long long		tmp;
	int				size;

	size = 0;
	if (m == 1)
		tab = "0123456789abcdef";
	else if (m == 2)
		tab = "0123456789ABCDEF";
	tmp = v;
	while (tmp /= b)
		size++;
	size = size + 1;
	if (!(str = (char *)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_abs(v % b)];
		size--;
		v /= b;
	}
	return (str);
}

char	*ft_itoa_b_m_ul(unsigned long long v, unsigned int b, int m)
{
	char			*str;
	char			*tab;
	unsigned long long		tmp;
	int				size;

	size = 0;
	if (m == 1)
		tab = "0123456789abcdef";
	else if (m == 2)
		tab = "0123456789ABCDEF";
	tmp = v;
	while (tmp /= b)
		size++;
	size = size + 1;
	if (!(str = (char *)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_abs(v % b)];
		size--;
		v /= b;
	}
	return (str);
}