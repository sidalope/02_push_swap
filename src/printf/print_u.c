/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:16:44 by abisiani          #+#    #+#             */
/*   Updated: 2025/09/16 12:44:01 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(unsigned int n)
{
	int	len;

	len = uintlen(n);
	put_unsnbr_fd(n, 1);
	return (len);
}
