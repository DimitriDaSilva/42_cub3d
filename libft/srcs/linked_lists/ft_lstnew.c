/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 08:31:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/15 16:38:47 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_node;

	if (!(new_node = malloc(sizeof(t_list))))
		return (0);
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
}
