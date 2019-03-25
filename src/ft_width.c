/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:17:02 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/25 16:53:05 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width2(int width, t_data *data)
{
	int		i;
	char	*ret;
	int		minus;

	minus = 0;
	if (data->flag & F_MINUS)
		minus = 1;
	i = 0;
	if (!(ret = malloc(sizeof(char) * (width - data->ap_sz + 1))))
		return (NULL);
	if (minus == 0)
	{
		if (width > data->ap_sz)
		{
			if (data->flag & F_ZERO)
				while (i < width - data->ap_sz)
				{
					ret[i] = '0';
					i++;
				}
			if (data->flag ^ F_ZERO)
				while (i < width - data->ap_sz)
				{
					ret[i] = ' ';		//remplacer par des . pour les tests
					i++;
				}
		}
	}
	if (data->flag & F_PLUS)
		ret[i++] = '+';
	ret[i] = '\0';
	return (ret);
}

char	*ft_width(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (flags[0] == '0')
		data->flag |= F_ZERO;
	if (flags[0] == '*')
	{
		i = data->tmp;
		data->flag &= ~F_WIDTH & ~F_STAR;
	}
	else
	{
		if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
			return (0);
		while (flags[i] == '+' || flags[i] < '0' || flags[i] > '9')
			i++;
		while (flags[i] >= '0' && flags[i] <= '9')
			conv[j++] = flags[i++];
		i = ft_atoi(conv);
		free(conv);
	}
	if (!(conv = ft_width2(i, data)))
		return (NULL);
	return (conv);
}

char	*ft_width_22(int width, t_data *data)
{
	int		i;
	char	*ret;

	i = 0;
	if (!(ret = malloc(sizeof(char) * (width - data->ap_sz + 1))))
		return (NULL);
	if (width > data->ap_sz)
	{
		if (data->flag & F_ZERO)
			while (i < width - data->ap_sz)
			{
				ret[i] = '0';
				i++;
			}
		if (data->flag ^ F_ZERO)
			while (i < width - data->ap_sz)
			{
				ret[i] = ' ';		//remplacer par des . pour les tests
				i++;
			}
	}
	if (data->flag & F_PLUS)
		ret[i++] = '+';
	ret[i] = '\0';
	return (ret);
}

char	*ft_width_2(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (flags[0] == '0')
		data->flag |= F_ZERO;
	if (flags[0] == '*')
	{
		i = data->tmp;
		data->flag &= ~F_WIDTH & ~F_STAR;
	}
	else
	{
		if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
			return (0);
		while (flags[i] == '+' || flags[i] < '0' || flags[i] > '9')
			i++;
		while (flags[i] >= '0' && flags[i] <= '9')
			conv[j++] = flags[i++];
		i = ft_atoi(conv);
		free(conv);
	}
	if (!(conv = ft_width_22(i, data)))
		return (NULL);
	return (conv);
}
