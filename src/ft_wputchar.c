/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:43:25 by okosiako          #+#    #+#             */
/*   Updated: 2017/02/21 16:43:32 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_wputchar_2(const uint32_t symbol, char *rt)
{
	if (symbol <= BIT21)
	{
		rt[0] = ((symbol & 1835008) >> 18) | 240;
		rt[1] = ((symbol & 258048) >> 12) | 128;
		rt[2] = ((symbol & 4032) >> 6) | 128;
		rt[3] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT26)
	{
		rt[0] = ((symbol & 50331648) >> 24) | 248;
		rt[1] = ((symbol & 16515072) >> 18) | 128;
		rt[2] = ((symbol & 258048) >> 12) | 128;
		rt[3] = ((symbol & 4032) >> 6) | 128;
		rt[4] = (symbol & 63) | 128;
	}
	else
	{
		rt[0] = ((symbol & 1073741824) >> 30) | 252;
		rt[1] = ((symbol & 1056964608) >> 24) | 128;
		rt[2] = ((symbol & 16515072) >> 18) | 128;
		rt[3] = ((symbol & 258048) >> 12) | 128;
		rt[4] = ((symbol & 4032) >> 6) | 128;
		rt[5] = (symbol & 63) | 128;
	}
}

int			ft_wputchar(const uint32_t symbol)
{
	char		*rt;
	int			ct;

	rt = ft_strnew(6);
	ct = 0;
	if (symbol <= BIT7)
		rt[0] = symbol;
	else if (symbol <= BIT11)
	{
		rt[0] = ((symbol & 1984) >> 6) | 192;
		rt[1] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT16)
	{
		rt[0] = ((symbol & 61440) >> 12) | 224;
		rt[1] = ((symbol & 4032) >> 6) | 128;
		rt[2] = (symbol & 63) | 128;
	}
	else
		ft_wputchar_2(symbol, rt);
	ct = write(1, rt, sizeof(char)) + write(1, &rt[1], ft_strlen(&rt[1]));
	ft_strdel(&rt);
	return (ct);
}

int			ft_wputstr(const wchar_t *wstr, int size)
{
	int		res;
	size_t	a;

	res = 0;
	a = 0;
	while (a < (size_t)size)
	{
		res += ft_wputchar(wstr[a]);
		a++;
	}
	return (res);
}
