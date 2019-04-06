/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxcapsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:12:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/06 18:37:40 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 6e321cfdcce0453becbba3b9146ad88924f89bab
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_octal(t_data *data)
{
	char				*final;
	char				*tmp;
	unsigned long long	ap;

	(void)ap;
	data->flag |= F_UNSIGNED;
	if (!(tmp = ft_conv_hhhlll_u(data, 8, 1)))
		return (NULL);
	if ((data->flag & F_SHARP) && (ft_strcmp(tmp, "0") != 0))
	{
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
		free(tmp);
	}
	else
		final = tmp;
	data->conv_sz = ft_strlen(final);
	if (ft_strcmp(tmp, "0") == 0)
	{
		if ((data->flag & F_SHARP) && (data->flag & F_PRECIS))
		{
			free(tmp);
			return (ft_strdup("0"));
		}
		if ((data->flag & F_SHARP) || (data->flag & F_PRECIS))
		{
			free(tmp);
			return (ft_strdup(""));
		}
		if ((data->flag & F_SHARP) || (data->flag & F_W_P))
		{
			free(tmp);
			return (ft_strdup(" "));
		}
	}
	return (final);
}

/*
** ft_hexa :
** Called from ft_only_conv for conv x ans X, mode 1 is x, mode 2 is X
*/

char	*ft_hexa(t_data *data, int mode)
{
	char				*final;
	char				*tmp;

	data->flag |= F_UNSIGNED;
	tmp = ft_conv_hhhlll_u(data, 16, mode);
	if (tmp[0] != '0' && tmp[1] != '\0' && (data->flag & F_SHARP) \
	&& !(data->flag & F_PRECIS) \
	&& !(data->flag & F_W_P) && !(data->flag & F_ZERO))
	{
		if (mode == 1)
			if (!(final = ft_strjoin("0x", tmp)))
				return (NULL);
		if (mode == 2)
			if (!(final = ft_strjoin("0X", tmp)))
				return (NULL);
	}
	else
		data->flag |= B_DONE;
	data->conv_sz = ft_strlen(final);
<<<<<<< HEAD
	if (tmp[0] == '0' && tmp[1] == '\0' && (data->flag & F_SHARP) \
	&& !(data->flag & F_PRECIS))
		if (!(final = (ft_strdup("0"))))
			return (NULL);
	if (tmp[0] == '0' && tmp[1] == '\0' && ((data->flag & F_SHARP) \
	|| data->flag & F_PRECIS))
		if (!(final = (ft_strdup(""))))
			return (NULL);
	if (tmp[0] == '0' && tmp[1] == '\0' && (data->flag & F_SHARP \
	|| data->flag & F_W_P))
		if (!(final = ft_strdup(" ")))
			return (NULL);
	if (data->flag & B_DONE)
	{
		data->flag &= ~ B_DONE;
		final = ft_strdup(tmp);
	}
	free(tmp);
=======
	if (ft_strcmp(tmp, "0") == 0)
	{
		if ((data->flag & F_SHARP) && !(data->flag & F_PRECIS))
		{
			free(tmp);
			return (ft_strdup("0"));
		}
		if ((data->flag & F_SHARP) || (data->flag & F_PRECIS))
		{
			free(tmp);
			return (ft_strdup(""));
		}
		if ((data->flag & F_SHARP) || (data->flag & F_W_P))
		{
			free(tmp);
			return (ft_strdup(" "));
		}
	}
>>>>>>> 6e321cfdcce0453becbba3b9146ad88924f89bab
	return (final);
}
