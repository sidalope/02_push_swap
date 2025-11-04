/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:55:28 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/15 18:50:56 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	return (str);
}

int	ft_atoi(char *str)
{
	long	res;
	int		minus;

	str = skip_whitespace(str);
	res = 0;
	minus = 0;
	if (*str)
	{
		if (*str == '-')
		{
			minus = 1;
			str++;
		}
		else if (*str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			res = res * 10 + *str++ - '0';
			if ((!minus && res > INT_MAX) || (minus && - res < INT_MIN))
				return (ps_error(), 0);
		}
		if (minus)
			res *= -1;
	}
	return ((int) res);
}
