/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:12:29 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/18 11:45:31 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	int		data;
	t_list	*next;
}				t_list;

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		tmp;
	t_list	*t_temp;

	t_temp = lst;
	while (lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = t_temp;
		}
		else
			lst = lst->next;
	}
	lst = t_temp;
	return (lst);
}
