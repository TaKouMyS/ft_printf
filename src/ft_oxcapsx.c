/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxcapsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:12:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/01 14:38:57 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base_mode(unsigned int v, unsigned int b, int m)
{
	char			*str;
	char			*tab;
	unsigned int	tmp;
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

char	*ft_octal(t_data *data)
{
	char			*final;
	int				ap;
	char			*tmp;

	ap = (va_arg(data->ap, int));
	data->flag |= UNSIGNED;
	if (ap < 0)
		data->flag |= AP_NEG;
	data->ap_sz = ft_intlen(ap);
	if ((data->flag & F_SHARP) && ap != 0)
	{
		tmp = ft_itoa_base_mode(ap, 8, 1);
		{
			if (!(final = ft_strjoin("0", tmp)))
				return (NULL);
		}
		free(tmp);
	}
	else
	{
		if (!(final = ft_itoa_base_mode(ap, 8, 1)))
			return (NULL);
	}
	return (final);
}

char	*ft_hexa(t_data *data)
{
	char			*final;
	int				ap;
	char			*tmp;

	ap = (va_arg(data->ap, int));
	data->flag |= UNSIGNED;
	if (ap < 0)
		data->flag |= AP_NEG;
	data->ap_sz = ft_intlen(ap);
	if ((data->flag & F_SHARP) && (ap != 0))
	{
		tmp = ft_itoa_base_mode(ap, 16, 1);
		{
			if (!(final = ft_strjoin("0x", tmp)))
				return (NULL);
		}
		free(tmp);
	}
	else
	{
		if (!(final = ft_itoa_base_mode(ap, 16, 1)))
			return (NULL);
	}
	return (final);
}

char	*ft_caps_x(t_data *data)
{
	char			*final;
	int				ap;
	char			*tmp;

	ap = (va_arg(data->ap, int));
	data->flag |= UNSIGNED;
	if (ap < 0)
		data->flag |= AP_NEG;
	data->ap_sz = ft_intlen(ap);
	if ((data->flag & F_SHARP) && (ap != 0))
	{
		tmp = ft_itoa_base_mode(ap, 16, 2);
		if (!(final = ft_strjoin("0X", tmp)))
			return (NULL);
		free(tmp);
	}
	else
	{
		if (!(final = ft_itoa_base_mode(ap, 16, 2)))
			return (NULL);
	}
	return (final);
}
