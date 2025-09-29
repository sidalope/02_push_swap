/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:53:17 by abisiani          #+#    #+#             */
/*   Updated: 2025/06/10 21:33:30 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	count;

	count = 0;
	if (n < 0 || n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len_n;
	char	*i_str;

	num = n;
	len_n = intlen(n);
	i_str = (char *) ft_calloc(len_n + 1, 1);
	if (!i_str)
		return (NULL);
	if (num == 0)
	{
		i_str[0] = '0';
		return (i_str);
	}
	if (num < 0)
	{
		i_str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		i_str[--len_n] = num % 10 + '0';
		num /= 10;
	}
	return (i_str);
}
