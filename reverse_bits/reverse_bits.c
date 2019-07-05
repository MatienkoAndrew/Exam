/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:33:50 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/05 16:42:16 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	reverse_bits(unsigned int octet)
{
	return (((octet >> 0) & 1) << 7) | \
		   (((octet >> 1) & 1) << 6) | \
		   (((octet >> 2) & 1) << 5) | \
		   (((octet >> 3) & 1) << 4) | \
		   (((octet >> 4) & 1) << 3) | \
		   (((octet >> 5) & 1) << 2) | \
		   (((octet >> 6) & 1) << 1) | \
		   (((octet >> 7) & 1) << 0);
}

int		main()
{
	unsigned int a = 65;
	printf("%i", reverse_bits(a));
	return (0);
}
