/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:35:21 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/18 11:44:57 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *tmp;
    t_list  *i;

    while (*begin_list && !cmp((*begin_list)->data, data_ref))
    {
        tmp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(tmp);
    }
    i = *begin_list;
    while (i && i->next)
    {
        if (!cmp(i->next->data, data_ref))
        {
            tmp = i->next;
            i->next = tmp->next;
            free(tmp);
        }
        if (i->next)
            i = i->next;
    }
}
