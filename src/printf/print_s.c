/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:52:38 by abisiani          #+#    #+#             */
/*   Updated: 2025/09/17 20:45:30 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(char *s)
{
	int		len;

	len = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (*s)
		len += write(1, s++, 1);
	return (len);
}
