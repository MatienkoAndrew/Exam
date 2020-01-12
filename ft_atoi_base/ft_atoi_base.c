/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:58:43 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/18 11:40:11 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     is_valid(char c, int base)
{
    char    digit[17] = "0123456789abcdef";
    char    digit1[17] = "0123456789ABCDEF";

    while (base--)
        if (digit[base] == c || digit1[base] == c)
            return (1);
    return (0);
}

int     value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    return (0);
}

int     ft_atoi_base(const char *str, int base)
{
    int     neg;
    int     res;

    res = 0;
    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;
    if (*str == '-')
        neg = 1;
    (*str == '+' || *str == '-') ? str++ : 0;
    while (is_valid(*str, base))
    {
        res = res * base + value(*str);
        str++;
    }
    if (neg == 1 && base == 10)
        res = -res;
    return (res);
}

int     main(int argc, char **argv)
{
    argc = 2;
    printf("%d", ft_atoi_base(argv[1], atoi(argv[2])));
    return (0);
}
