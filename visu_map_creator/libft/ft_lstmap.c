/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:17:03 by qudesvig          #+#    #+#             */
/*   Updated: 2018/11/20 11:09:09 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	ft_lstadd(&new, f(lst));
	lst = lst->next;
	tmp = new;
	while (lst != NULL)
	{
		tmp->next = f(lst);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
