/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prc_minus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/08 21:38:55 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_minus_s(int before, int after, char *final, t_data *data)
{
	char	*ap;

	ap = ft_strdup(data->tmp_s);
	free(final);
	if (!(final = ft_strsub(ap, 0, after)))
		return (NULL);
	if (before > after)
		data->width_precis_minus = before - after;
	if (after >= before)
		data->width_precis_minus = before - data->conv_sz;
	if (ap[0] == '\0' && before > after)
		data->width_precis_minus = before;
	if (ap[0] == '\0' && before <= after)
		data->width_precis_minus = after;
	free(ap);
	return (final);
}

static char		*ft_else(char *final, int before, int after, t_data *data)
{
	int		surplus;
	int		i;

	surplus = 0;
	i = 0;
	if (data->f & F_PLUS)
	{
		surplus = 1;
		final[i++] = '+';
	}
	while (i < after - data->conv_sz + surplus)
		final[i++] = '0';
	final[i] = '\0';
	if (before > after)
		data->width_precis_minus = before - i - data->conv_sz;
	return (final);
}

char			*ft_flag_minus(int before, int after, char *final, t_data *data)
{
	int		i;

	i = 0;
	if (data->f & F_S)
		final = ft_minus_s(before, after, final, data);
	else
	{
		if (data->f & AP_NEG && !(data->f & F_UNSIGNED))
		{
			final[i++] = '-';
			while (i < after - data->conv_sz + 1)
				final[i++] = '0';
			final[i] = '\0';
			if (after == 0)
				data->width_precis_minus = 0;
		}
		else
			ft_else(final, before, after, data);
	}
	return (final);
}
